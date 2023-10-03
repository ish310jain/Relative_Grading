#include <iostream>
#include <memory>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include "json-1.hpp"

using json = nlohmann::json;
using tcp = boost::asio::ip::tcp;
namespace websocket = boost::beast::websocket;

class ClientHandler : public std::enable_shared_from_this<ClientHandler>
{
private:
    websocket::stream<tcp::socket> ws_;
    boost::beast::flat_buffer buffer_;
    tcp::endpoint remote_endpoint_;

public:
    explicit ClientHandler(tcp::socket socket)
        : ws_(std::move(socket))
    {
        remote_endpoint_ = ws_.next_layer().remote_endpoint();
        std::cout << "Client connected: " << remote_endpoint_ << std::endl;
        // std::cout << std::endl;
    }

    ~ClientHandler()
    {
        std::cout << "Client disconnected: " << remote_endpoint_ << std::endl;
    }

    void start()
    {
        ws_.async_accept(
            boost::asio::bind_executor(
                ws_.get_executor(),
                std::bind(
                    &ClientHandler::onAccept,
                    shared_from_this(),
                    std::placeholders::_1)));
    }

private:
    void onAccept(boost::beast::error_code ec)
    {
        if (ec)
        {
            std::cerr << "WebSocket accept error: " << ec.message() << std::endl;
            return;
        }

        doRead();
    }

    void doRead()
    {
        ws_.async_read(
            buffer_,
            boost::asio::bind_executor(
                ws_.get_executor(),
                std::bind(
                    &ClientHandler::onRead,
                    shared_from_this(),
                    std::placeholders::_1,
                    std::placeholders::_2)));
    }

    void onRead(boost::beast::error_code ec, std::size_t)
    {
        if (ec == websocket::error::closed)
            return;

        if (ec)
        {
            std::cerr << "WebSocket read message: " << ec.message() << std::endl;
            return;
        }

        // Echo the received message back to the client
        std::string message = boost::beast::buffers_to_string(buffer_.data());
        std::cout << "Received message from " << remote_endpoint_ << ": " << std::endl;
        std::cout << std::endl;

        // Parse the received message as JSON
        try
        {
            nlohmann::json receivedJson = nlohmann::json::parse(message);

            std::string systemName = receivedJson["system_name"];
            std::cout << "System Name: " << systemName;

            if (receivedJson.find("ram_usage_mb") != receivedJson.end() && !receivedJson["ram_usage_mb"].is_null())
            {
                double memoryUsageMB = receivedJson["ram_usage_mb"];
                std::cout << "Memory Usage: " << std::fixed << std::setprecision(2) << memoryUsageMB << " MB" << std::endl;
            }
            else
            {
                std::cout << "Memory Usage not provided or is null." << std::endl;
            }

            if (receivedJson.find("cpu_utilization") != receivedJson.end() && receivedJson["cpu_utilization"].is_number_float())
            {
                double cpuUtilization = receivedJson["cpu_utilization"];
                std::cout << "CPU Utilization: " << std::fixed << std::setprecision(2) << cpuUtilization << "%" << std::endl;
            }
            else
            {
                std::cout << "CPU Utilization not provided or is not a valid double value." << std::endl;
            }
            std::cout << std::endl;
        }
        catch (const nlohmann::json::parse_error &e)
        {
            std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        }

        // Clear the buffer and start a new read operation
        buffer_.consume(buffer_.size());
        doRead();
    }
};

class WebSocketServer
{
private:
    boost::asio::io_context &io_context_;
    tcp::acceptor acceptor_;

public:
    WebSocketServer(boost::asio::io_context &io_context, short port)
        : io_context_(io_context), acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {}

    void startAccept()
    {
        acceptor_.async_accept(
            [this](boost::beast::error_code ec, tcp::socket socket)
            {
                if (!ec)
                {
                    std::make_shared<ClientHandler>(std::move(socket))->start();
                }
                startAccept();
            });
    }
};

int main()
{
    try
    {
        boost::asio::io_context io_context;

        const short port = 8080;
        WebSocketServer server(io_context, port);
        server.startAccept();

        std::cout << "Server listening on port " << port << "..." << std::endl;
        std::cout << std::endl;

        io_context.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
