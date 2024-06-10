#include "pch.h"
#include "Customer.h"

unsigned int count = 1;
std::mutex customerMutex;

std::string &trim(std::string &str)
{
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch)
                                        { return !std::isspace(ch); }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch)
                           { return !std::isspace(ch); })
                  .base(),
              str.end());
    return str;
}

void parseCSV(std::vector<Customer> *customers, std::string filename, char delimiter = ',')
{
    std::vector<Customer> customersLocal;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string token;
        bool inQuotes = false;
        std::vector<std::string> fields; // store parsed fields

        while (std::getline(iss, token, delimiter))
        {
            if (token.front() == '"' && token.back() == '"')
            {                                              // Handle quoted field (simple case)
                token = token.substr(1, token.size() - 2); // Remove the quotes
            }
            else if (token.front() == '"')
            { // Start of a quoted field (with commas)
                inQuotes = true;
                token.erase(0, 1); // Remove the opening quote
            }

            if (inQuotes)
            {
                if (token.back() == '"')
                {
                    inQuotes = false;
                    token.pop_back(); // Remove the closing quote
                }
                if (!fields.empty())
                { // Add to the previous token if we are still in quotes
                    fields.back() += delimiter + token;
                }
                else
                {
                    fields.push_back(token);
                }
            }
            else
            {
                fields.push_back(token);
            }
        }

        if (fields.size() == 12)
        { // Assuming 12 columns (adjust if needed)
            try
            {

                customersLocal.push_back(Customer(count++, trim(fields[1]), trim(fields[2]),
                                                  trim(fields[3]), trim(fields[4]), trim(fields[5]),
                                                  trim(fields[6]), trim(fields[7]), trim(fields[8]),
                                                  trim(fields[9]), trim(fields[10]), trim(fields[11])));
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error parsing line: " << line << " - " << e.what() << std::endl;
            }
        }
    }
    std::lock_guard<std::mutex> lock(customerMutex);
    customers->insert(customers->end(), customersLocal.begin(), customersLocal.end());
}

int main()
{
    std::vector<Customer> customers;
    std::string files[] = {"data/customers-1000000.csv", "data/customers-100000.csv", "data/customers-10000.csv", "data/customers-1000.csv",
                           "data/customers-100.csv", "data/customers-2000000.csv", "data/customers-500000.csv"};

    // Read Data
    auto start = std::chrono::high_resolution_clock::now();
//#define USE_THREADS

#ifdef USE_ASYNC
    std::cout << "Reading ASYNC\n";
    std::vector<std::future<void>> futures;
    for (auto file : files)
    {
        futures.emplace_back(std::async(std::launch::async, parseCSV, &customers, file, ','));
    }
    for (auto &future : futures)
    {
        future.wait();
    }

#endif

#ifdef USE_THREADS // Use #ifdef instead of #elif here
    std::cout << "Reading with Threads\n";
    std::vector<std::thread> threads;
    for (auto file : files)
    {
        threads.emplace_back(parseCSV, &customers, file, ',');
    }
    for (auto &thread : threads)
    {
        thread.join();
    }

#endif

#ifndef USE_ASYNC
#ifndef USE_THREADS
    std::cout << "Reading ...\n";
    for (auto file : files)
    {
        parseCSV(&customers, file, ',');
    }
#endif
#endif

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Read Time: " << duration.count() << " ms" << std::endl;


}
// Display Data
// start = std::chrono::high_resolution_clock::now();
// std::cout << std::left << std::setw(8) << "Index" << std::setw(20) << "Customer ID"
//           << std::setw(15) << "First Name" << std::setw(15) << "Last Name" << std::setw(20) << "Company"
//           << std::setw(22) << "City" /*<< std::setw(35) << "Country"*/
//           << std::setw(25) << "Phone 1" << std::setw(25) << "Phone 2" << std::setw(35) << "Email"
//           << std::setw(15) << "Sub. Date" << std::setw(25) << "Website" << std::endl;
// std::cout << std::string(230, '-') << std::endl; // Separator line

// for (auto customer : customers)
// {
//     std::cout << customer;
// }

//     end = std::chrono::high_resolution_clock::now();
//     duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
//     std::cout << "Display Time: " << duration.count() << " milliseconds" << std::endl;
// }
