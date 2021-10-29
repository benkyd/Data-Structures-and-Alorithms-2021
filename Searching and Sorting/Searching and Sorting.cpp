#include <iostream>
#include <vector>

template <typename T>
void PrintVector(std::vector<T> v)
{
	for (const auto& e : v)
		std::cout << e << ", ";
	std::cout << std::endl;
}

void Swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

std::vector<int> SelectionSort(std::vector<int> in)
{
	for (int i = 0; i < in.size(); i++)
	{
		int indexOfSmallest = i;
		for (int j = i; j < in.size(); j++)
		{
			if (in[indexOfSmallest] > in[j])
			{
				indexOfSmallest = j;
			}
		}
		if (indexOfSmallest != i)
		{
			Swap(&in[i], &in[indexOfSmallest]);
		}
	}
	return in;
}

std::vector<int> InsersionSort(std::vector<int> in)
{
	for (int i = 0; i < in.size(); i++)
	{
		int itemToInsert = in[i];
		int indexHole = i;
		while (indexHole > 0 && in[indexHole - 1] > itemToInsert)
		{
			in[indexHole] = in[indexHole - 1];
			indexHole--;
		}

		in[indexHole] = itemToInsert;
	}
	return in;
}

std::vector<int> BubbleSort(std::vector<int> in)
{
	for (int i = 0; i < in.size(); i++)
	{
		for (int j = 0; j < in.size() - 1; j++)
		{
			if (in[j] > in[j + 1])
			{
				Swap(&in[j], &in[j + 1]);
			}
		}
	}
	return in;
}

int LinearSearch(std::vector<int> vals, int lookup)
{
	for (const auto& i : vals)
	{
		if (i == lookup)
		{
			return lookup;
		}
	}
}


std::vector<int> SubsetVector(std::vector<int> in, int start, int end)
{
	std::vector<int> result(start - end + 1);
	std::copy(in.begin() + start, in.begin() + end + 1, result.begin());
	return result;
}

int BinarySearch(std::vector<int> set, int lookup)
{
	if (set[set.size() / 2] == lookup) return lookup;
	if (set[set.size() / 2] > lookup) return BinarySearch(SubsetVector(set, set.size() / 2, set.size()), lookup);
	if (set[set.size() / 2] < lookup) return BinarySearch(SubsetVector(set, 0, set.size() / 2), lookup);
}


int TernarySearch(std::vector<int> set, int lookup)
{
	if (set.size() == 1) return set[0];
	if (set.size() == 2) return BinarySearch(set, lookup);

	int firstThird = 0;
	int secondThird = set.size() / 3;
	int thirdThird = (set.size() / 3) * 2;
	int lastThird = set.size();

	if (set[firstThird] > lookup && set[secondThird] < lookup) return TernarySearch(SubsetVector(set, firstThird, secondThird), lookup);
	if (set[secondThird] > lookup && set[thirdThird] < lookup) return TernarySearch(SubsetVector(set, secondThird, thirdThird), lookup);
	if (set[thirdThird] > lookup && set[lastThird] < lookup)   return TernarySearch(SubsetVector(set, thirdThird, lastThird), lookup);
}

int main()
{
	std::vector<int> sorted;

	sorted = SelectionSort({ 1, 4, 3, 5, 7, 4, 3, 7, 8, 2, 10, 5, 100 });

	PrintVector(sorted);

	sorted = InsersionSort({ 1, 4, 3, 5, 7, 4, 3, 7, 8, 2, 10, 5, 100 });

	PrintVector(sorted);

	sorted = BubbleSort({ 1, 4, 3, 5, 7, 4, 3, 7, 8, 2, 10, 5, 100 });

	PrintVector(sorted);


	std::cout << std::endl;


	int lookup = 0;

	lookup = LinearSearch(BubbleSort({ 1, 4, 3, 5, 7, 4, 3, 7, 8, 2, 10, 5, 100 }), 5);
	std::cout << lookup << std::endl;

	lookup = BinarySearch(BubbleSort({ 1, 4, 3, 5, 7, 4, 3, 7, 8, 2, 10, 5, 100 }), 5);
	std::cout << lookup << std::endl;

	lookup = TernarySearch(BubbleSort({ 1, 4, 3, 5, 7, 4, 3, 7, 8, 2, 10, 5, 100 }), 5);
	std::cout << lookup << std::endl;
}

