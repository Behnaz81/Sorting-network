#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> reading_network(int num_of_inputs)
{ 
	vector<string> network;
    for (int i = 0; i < num_of_inputs; i++)
	{
		string a;
		cin >> a;
		network.push_back(a);
	}
	return network;
}

vector<int> reading_inputs(int num_of_inputs)
{
vector<int>numbers;
   
	for (int j = 0; j < num_of_inputs; j++)
	{
		int b;
		cin >> b;
		numbers.push_back(b);
	}
	return numbers;
}

bool is_network_valid(vector<string> network, int num_of_stages)
{
	for (int i = 0; i < num_of_stages; i++)
	{
		for (int j = 0; j < network.size(); j++)
		{
			if (network[j][i] != '-')
			{
				if (network[j][i] < 'a' && network[j][i] > 'z')
				{
					return false;
				}
				if (network[j].size() != num_of_stages)
				{
                    return false;
				}	

				int cnt = 1;
				for (int k = j + 1; k < network.size(); k++)
				{
					if (network[j][i] == network[k][i])
					{
							cnt++;
							
					}
				}
				if (cnt == 2)
				{
					break;
				}
				else
				{
                    return false;
				}
					
			}
		}
	}
	return true;
}

void process(int num_of_inputs,int num_of_stages,vector<string> arr,vector<int> &inpt)
{
	for (int i = 0; i < num_of_stages; i++)
	{
		for (int j = 0; j < num_of_inputs - 1; j++)
		{
			if (arr[j][i] != '-')
			{
					for (int k = j + 1; k < num_of_inputs; k++)
					{
						if (arr[j][i] == arr[k][i])
						{
							if (inpt[j] > inpt[k])
							{
								char temp = inpt[j];
								inpt[j] = inpt[k];
								inpt[k] = temp;
							}
						}
					}
				
			}
		}
	}
}

void outputGenerating(int num_of_inputs,vector<int> inpt)
{
	bool flag = false;
		for (int i = 0; i < num_of_inputs - 1; i++)
		{
			if (inpt[i] > inpt[i + 1])
			{
				flag = true;
			}
			
		}
		if (!flag)
			{
				cout << "Sorted!\n";
			}
		else
		{
			cout << "Not sorted!\n";
		}
}

int main()
{
	int num_of_inputs;
	int num_of_stages; 
	vector<string>network;
	vector<int>numbers;
	cin >> num_of_inputs >> num_of_stages;
	network = reading_network(num_of_inputs);
	numbers = reading_inputs(num_of_inputs);
	if (!is_network_valid(network, num_of_stages))
	{
		cout << "Invalid network!\n";
		return -1;
	}
	process(num_of_inputs, num_of_stages, network, numbers);
	outputGenerating(num_of_inputs, numbers);
	return 0;
}