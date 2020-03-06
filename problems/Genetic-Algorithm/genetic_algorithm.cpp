#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

class DNA {

	char generate_genes() {
		char gene;
		gene = rand() % 91 + 32;
		return gene;
	}

	public:
		std::vector<char> genes;
		float fitness;

		DNA(int len) {
			for (int i = 0; i < len; i++) {
				genes.push_back(generate_genes());
			}
		}

		void calcFitness(string target) {
			float count = 0;
			for (int i= 0; i < genes.size(); i++) {
				if (genes[i] == target[i]) {
					count++;
				}
			}
			// evaluate the fitness of this genes
			fitness = count / target.size();
		}

		DNA crossover(DNA partner) {
			DNA child(genes.size());
			int probability = rand() % genes.size();

			for (int i=0; i < genes.size(); i++)  {
				if (probability > i) child.genes[i] = genes[i];
				else 				 child.genes[i] = partner.genes[i];
			}
			return child;
		}

		void mutate() {
			for (int i= 0; i < genes.size(); i++) {
				if (rand() % 100 < 2) {
					genes[i] = generate_genes();
				}
			}
		}

		string get_phrase() {
			string s = "";
			for (int i= 0; i < genes.size(); i++) {
				s += genes[i];
			}
			return s;
		}

};


int main() 
{
	srand(time(NULL));

	string target, word_found, best_word;
	int max_pop;
	bool done = false;
	int generation = 0;
	float best_fitness = 0;
	int index;


	cout << "Enter the target word: ";
	getline(cin, target);

	cout << "Set the max population: ";
	cin >> max_pop;
	// create a population of DNA
	// DNA population[max_pop](target.size());
	std::vector<DNA> population;
	for (int i = 0; i< max_pop; i++) {
		population.push_back(DNA(target.size()));
	}

		while (!done) {
			// calculte the fitness of individul DNA
			for (int i = 0; i < max_pop; i++) {
				population[i].calcFitness(target);
			}

			// create a mating pool of DNA who pass the fitness
			std::vector<DNA> mating_pool;
			for (int i = 0; i < max_pop; i++) {
				int n = int(population[i].fitness * 100);
				for (int j = 0; j < n; j++) {
					mating_pool.push_back(population[i]);
				}
			}

			// get a parent from the mating pool and do a crossover!
			for (int i = 0; i < max_pop; i++) {
				DNA parentX = mating_pool[rand() % mating_pool.size()];
				DNA parentY = mating_pool[rand() % mating_pool.size()];

				DNA child = parentX.crossover(parentY);
				child.mutate();
				population[i] = child;
			}

			for (int i= 0; i< max_pop; i++) {
				population[i].calcFitness(target);

				// show the evolve words
				string evolve = population[i].get_phrase();
				cout << setw(50) << i  << " " << evolve << endl;

				if (population[i].fitness > best_fitness) {
					best_fitness = population[i].fitness;
					index = i;
				}
				if (int(population[i].fitness) == 1) {
					word_found = population[i].get_phrase();
					done = true;
					break;
				}
			}

		best_word = population[index].get_phrase();
		cout << setw(5) << "Best word so far: " << best_word << endl;
		cout << setw(5) << "At index: " << index << endl;
		cout << setw(5) << "Generation: " << generation << endl;
		cout << setw(5) << "Population: " << max_pop << endl;
		cout << setw(5) << "Best fitness score: " << best_fitness << endl;
		generation++;
	}

	cout << "\n==========================================" << endl;
	cout << "Word found: " << word_found << endl;
	cout << "==========================================" << endl;

	return 0;
}