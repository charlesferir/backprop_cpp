#include <Eigen/Eigen>
#include <cxxopts.hpp>
#include <iostream>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

auto console = spdlog::stdout_color_mt("main.cpp");

int main(int argc, char** argv)
{
    cxxopts::Options options("backprop_cpp",
                             "A backprop implementation for 'fun'!");

    options.add_options() // clang-format off
        ("b,bar", "Param bar", cxxopts::value<std::string>()) 
        ("d,debug", "Enable debugging.", cxxopts::value<bool>()->default_value("false")) 
        ("f,foo", "Param foo.", cxxopts::value<int>()->default_value("10")) 
        ("h,help", "Print usage."); // clang-format on

    auto result = options.parse(argc, argv);
    bool debug = result["debug"].as<bool>();
    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(0);
    }
    if (debug)
        console->set_level(spdlog::level::debug);

    console->debug("test log");

    Eigen::Matrix<int, 2, 3> a({{1, 2, 3}, {4, 5, 6}});
    Eigen::Matrix<int, 3, 2> b(a.transpose());
    std::cout << "Hello, world!\n" << a << "\n\n" << b << debug;
}
