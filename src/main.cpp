#include <iostream>
#include "k_means.h"
#include <vector>
#include <cmath>


int main(int argc, const char * argv[])
{
	
	using km_type = utils::k_means<double, 2>;
	
	km_type::population_type input =
	{
		{0.0, 0.0},
		{0.2, -0.1},
		{1.0, 1.0},
		{1.2, 0.8},
		{-1.0, -1.0},
		{-1.1, -0.9}
	};

	km_type km(input, 3);
	
	for (auto i = 0; i < km.clusters().size(); ++i)
	{
		auto& cluster = km.clusters()[i];
		
		std::cout << "cluster " << i;
		std::cout << " - centroid: " << cluster.centroid();
		std::cout << ", sigma: " << cluster.sigma();
		std::cout << ", members: " << std::endl;
		for (auto it = cluster.members().cbegin(); it != cluster.members().cend(); ++it)
		{
			std::cout << "population[" << *it << "] : " << input[*it] << std::endl;
		}
	}
	
	auto& result_vec = km.result_vector();
	for (auto i = 0; i < result_vec.size(); ++i)
	{
		auto icluster = result_vec[i];
		std::cout << "input element " << i << " " << input[i] << " is a member of cluster " << icluster << std::endl;
	}
    return 0;
}
