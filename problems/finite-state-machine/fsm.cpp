#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> PLACES = {"Alicia", "Echague", "Santiago", "Ramon", "San Mateo", "San Isidro"};

vector<vector<int>> GRAPH = {
	{1, 4, 5},
	{0, 5, 5},
	{5, 3, 5},
	{2, 4, 5},
	{0, 3, 5},
	{0, 1, 2, 3, 4}
};

vector<vector<int>> WEIGHTS = {
	{22, 16, 22},
	{22, 22, 6},
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
}

int sum_route_weights(vector<int> route, vector<int> edges) {
	int sum = 0;
	
	for (int i = 0; i < route.size(); i++) {
		if (i < route.size()-1)sum += WEIGHTS[route[i]][edges[i]];
	}

	return sum;
}

void pathFinder(int init, int final) 
{
	bool finished = false;
	int vertex = init;
	int edge = 0;
	int next_vertex;
	int previous = 999;

	
	int lowest_weight = 999;
	int highest_weight = 0;
	int weight;
	vector<int> shortest_path;
	vector<int> longest_path;


	vector<int> route;
	vector<int> edge_record = {0,0,0,0,0,0,0};

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
			edge_record[vertex] = edge;
			if (route.size() > 0) {
				weight = sum_route_weights(route, edge_record);

				if (weight < lowest_weight) {
					lowest_weight = weight;
					shortest_path = route;
				}
				if (weight > highest_weight)  {
					highest_weight = weight;
					longest_path = route;
				}

				//display_path(route);
				//cout << "total: " << weight << " km" << endl;
				previous = route[route.size()-1];

				route.pop_back();
				
				vertex = route[route.size()-1];
				edge_record[previous] = 0;
			}

		}


		if (route.size() == 0) finished = true;
	}

	cout << endl << endl;

	cout << "Shortest Path: ";
	display_path(shortest_path);
	//cout << "Total: " << lowest_weight << " km" << endl;
	cout << endl;

	cout << "Longest Path: ";
	display_path(longest_path);
	//cout << "Total: " << highest_weight << " km" << endl;
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
