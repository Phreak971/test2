#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>
#include <fstream>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <thread>
// ... other headers (if using XML or threads)

struct Message {
    std::string username;
    std::string timestamp;
    std::string message;
};

class MessageHistory {
public:
    MessageHistory(int max_messages = 100) : max_messages_(max_messages) {}

    void addMessage(const Message& msg) {
        std::lock_guard<std::mutex> lock(mutex_);
        messages_.push_back(msg);
        if (messages_.size() > max_messages_) {
            messages_.erase(messages_.begin());
        }
    }

    std::vector<Message> getMessages() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return messages_;
    }

private:
    int max_messages_;
    std::vector<Message> messages_;
    std::mutex mutex_;
};

int main() {
    // Initialize server socket and bind to port
    int server_socket;
    struct sockaddr_in server_address;

    // ... (Socket setup code)

    // Create MessageHistory object
    MessageHistory message_history;

    // Function to handle client connections (use threads if needed)
    void handleClient(int client_socket) {
        // Receive client username and welcome message
        // ...

        // Thread-safe access to message history
        std::vector<Message> messages = message_history.getMessages();
        // Send existing messages to client
        // ...

        while (true) {
            // Receive message from client
            // ...
            if (message.empty()) {
                break; // Client disconnected
            }

            // Update timestamp and append to message history
            message.timestamp = getTimestamp(); // Function to generate timestamp
            message_history.addMessage(message);

            // Broadcast message to all clients (use sockets)
            // ...
        }

        close(client_socket); // Close client connection
    }

    // Listen for incoming connections and spawn threads for clients
    while (true) {
        // Accept connections and create threads/processes
        int client_socket = accept(server_socket, nullptr, nullptr);
        std::thread client_thread(handleClient, client_socket);
        client_thread.detach(); // Detach thread or manage it
    }

    close(server_socket); // Close server socket
    return 0;
}
