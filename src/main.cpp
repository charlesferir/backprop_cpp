#include <iostream>
#include <memory>
#include <random>
#include <string>

#include <Eigen/Eigen>
#include <cxxopts.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

auto console = spdlog::stdout_color_mt("main.cpp");

long unsigned int seed = 666;
std::default_random_engine generator{seed};
std::normal_distribution<double> distribution(0.0, 1.0);

class Network 
{
public:
    Network(std::vector<int>&& layers) : layers(layers){
        for(int layer : layers) {
            weights.push_back(std::move(Eigen::VectorXd(layer)));
            for(int i = 0; i < layer; i++) {
                weights.back()[i] = distribution(generator);
            }
        }

        for(auto weight : weights) 
            std::cout << weight << "\n\n";
    }

private:
    std::vector<int> layers;
    std::vector<Eigen::VectorXd> weights;
};

int main(int argc, char** argv)
{
    cxxopts::Options options("backprop_cpp",
                             "A backprop implementation for 'fun'!");

    options.add_options() // clang-format off
        ("b,bar", "Param bar", cxxopts::value<std::string>())
        ("d,debug", "Enable debugging.", cxxopts::value<bool>()->default_value("false"))
        ("f,foo", "Param foo.", cxxopts::value<int>()->default_value("10"))
        ("l,layers", "Layers of the network.", cxxopts::value<std::vector<int>>())
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

    std::vector<int> layers = result["layers"].as<std::vector<int>>();
    std::unique_ptr<Network> nn = std::make_unique<Network>(std::move(layers));
}
