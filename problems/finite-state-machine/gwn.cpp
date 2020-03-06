#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> PLACES = {"Alicia", "Echague", "Santiago", "Ramon", "San Mateo", "San Isidro"};
vector<vector<int>> GRAPH = {
	{1, 4, 5},
	{0, 2, 5},
	{1, 3, 5},
	{2, 4, 5},
	{0, 3, 5},
	{0, 1, 2, 3, 4}
};

vector<vector<int>> WEIGHTS = {
	{22, 16, 22},
	{22, 22, 19},
	{12, 12, 15},
	{12, 12, 14},
	{16, 12, 21},
	{22, 19, 15, 14, 21}
};

void show_places()
{
	for (int i = 0; i < PLACES.size(); i++) 	cout << "[" << i << "] " << PLACES[i] << endl;
	cout << endl;	 
}

bool not_includes(int vertex, vector<int> route)
{
	for (int v : route) {
		if (vertex == v) return false;
	}
	return true;
}

void display_path(vector<int> path)
{
	for (int x : path) cout << PLACES[x] << " -> ";
	// for (int i = 0; i < path.size(); i++) {
	// 	for (int j = 0; j < path[i].size(); j++) {
	// 		cout << PLACES[j] << " -> ";
	// 	}
	// 	cout << endl;
	// }
	cout << "DONE!" << endl;
}

int sum_route_weights(vector<int> route) {
	int sum = 0;
	for (int i : route) sum += i;
	return sum;
}

void pathFinder(int init, int final) 
{
	bool finished = false;
	int vertex = init;
	int edge = 0;
	int next_vertex;
	int previous = 0;

	vector<int> route;
	int edge_record[6] = {0};

	route.push_back(init);


	while (!finished) {
		edge = edge_record[vertex];
		next_vertex = GRAPH[vertex][edge];
		if (not_includes(next_vertex, route) && next_vertex != previous) {
			route.push_back(next_vertex);
			vertex = next_vertex;

		} else {
			edge++;
			previous = 999;
			if (edge < GRAPH[vertex].size()) {
		
				edge_record[vertex] = edge;
			}
			else {
				previous = route[route.size()-1];
				edge_record[previous] = 0;
				route.pop_back();
				vertex = route[route.size()-1];
			}
		}

		if (vertex == final) {
			display_path(route);
			previous = route[route.size()-1];
			route.pop_back();

			vertex = route[route.size()-1];
			edge_record[previous] = 0;

		}

		if (route.size() <= 0) finished = true;
	}
}

int main()
{
	int initial_state, final_state;

	show_places();
	
	cout << "Initial State: ";
	cin >> initial_state;

	cout << "Final State: ";
	cin >> final_state;

	pathFinder(initial_state, final_state);
	return 0;
}