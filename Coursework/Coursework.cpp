#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

/**
* \brief  Fills 2D array from keyboard.
* \params rows - array rows, columns - array columns, message - request for entering a new element.
* \return Filled 2D array.
*/
int32_t** array_keyboard_filling(const size_t rows, const size_t columns, const string& message);

/**
* \brief  Fills 2D array with random numbers.
* \params rows - array rows, columns - array columns;
* \return Filled 2D array.
*/
int32_t** array_random_filling(const size_t rows, const size_t columns);

/**
* \brief Check is number negative.
* \params number - number.
* \return True if number is negative, else - False.
*/
bool is_negative(const int32_t number);

/**
* \brief Create an 1D array with column maximums of 2D array.
* \params array - 2D array, rows - array rows, columns - array columns.
* \return Array of column maximums.
*/
int32_t* create_1D_array_of_maxs(int32_t** array, const size_t rows, const size_t columns);

/**
* \brief Create a sorted 1D array from 2D array.
* \params array - 2D array, rows - array rows, columns - array columns.
* \return Sorted 1D array.
*/
int32_t* create_sorted_1D_array(int32_t** array, const size_t rows, const size_t columns);

/**
* \brief Counts a sum of negative elements of 2D array.
* \param array - 2D array, rows - array rows, columns - array columns.
* \return Sum of negative elemets.
*/
int32_t get_sum_of_negative_els(int32_t** array, const size_t rows, const size_t columns);

/**
* \brief Sorts an array with bubble sort algorithm
* \param array - 1D array, size - size of array
* \return Sorted array.
*/
int32_t* bubble_sort(int32_t* array, const size_t size);

/**
* \brief Users choice of array filling.
*/
enum class User_Choice {
	keyboard_filling, random_filling, get_sum_of_negative_els,
	create_sorted_1D_array, create_1D_array_of_maxs,
	print_2D_array, exit
};

/**
* \brief Prints an array.
* \param array - array, rows - number of rows, columns - number of columns.
*/
void print_2D_array(int32_t** array, const size_t rows, const size_t columns);

/**
* \brief Prints an array.
* \param array - array, size - size of array.
*/
void print_1D_array(int32_t* array, const size_t size);

/**
* \brief Deletes an array.
* \param array - array, rows - number of rows, columns - number of columns.
*/
void delete_2D_array(int32_t** array, const size_t rows);

/**
* \brief Deletes an array.
* \param array - array.
*/
void delete_1D_array(int32_t** array);

int main()
{
	cout << "Enter number of rows: ";
	size_t rows;
	cin >> rows;

	cout << "Enter number of columns: ";
	size_t columns;
	cin >> columns;

	int32_t** my_matrix = new int32_t * [rows];
	for (size_t i = 1; i != rows; i++)
	{
		my_matrix[i] = nullptr;
	}

	int32_t* sorted_array = new int[rows * columns];
	int32_t* array_of_maxs = new int[columns];

	bool end_of_program = false;

	while (!end_of_program)
	{
		cout << '\n' << "Choose what you want to do: \n"
			<< static_cast<int>(User_Choice::keyboard_filling) << " - keyboard filling,\n"
			<< static_cast<int>(User_Choice::random_filling) << " - random filling,\n"
			<< static_cast<int>(User_Choice::get_sum_of_negative_els) << " - get sum of negative elements of array,\n"
			<< static_cast<int>(User_Choice::create_sorted_1D_array) << " - from elements of 2D array create sorted 1D array,\n"
			<< static_cast<int>(User_Choice::create_1D_array_of_maxs) << " - create 1D array of 2D column maximums,\n"
			<< static_cast<int>(User_Choice::print_2D_array) << " - print an array,\n"
			<< static_cast<int>(User_Choice::exit) << " - exit,\n"
			<< "Your choice is ";

		int input;
		cin >> input;
		cout << '\n';

		const auto choice = static_cast<User_Choice>(input);

		const string message = "Enter the element of the array";
		switch (choice)
		{
		case User_Choice::keyboard_filling:
		{
			my_matrix = array_keyboard_filling(rows, columns, message);
			print_2D_array(my_matrix, rows, columns);
			break;
		};
		case User_Choice::random_filling:
		{
			my_matrix = array_random_filling(rows, columns);
			print_2D_array(my_matrix, rows, columns);
			break;
		};
		case User_Choice::get_sum_of_negative_els:
		{
			if (my_matrix[0] != nullptr)
				cout << get_sum_of_negative_els(my_matrix, rows, columns);
			else
				cout << "An array is not initialized" << endl;
			break;
		};
		case User_Choice::create_sorted_1D_array:
		{
			if (my_matrix[0] != nullptr)
			{
				sorted_array = create_sorted_1D_array(my_matrix, rows, columns);
				print_1D_array(sorted_array, rows * columns);
			}
			else
				cout << "An array is not initialized" << endl;
			break;
		};
		case User_Choice::create_1D_array_of_maxs:
		{
			if (my_matrix[0] != nullptr)
			{
				array_of_maxs = create_1D_array_of_maxs(my_matrix, rows, columns);
				print_1D_array(array_of_maxs, columns);
			}
			else
				cout << "An array is not initialized" << endl;
			break;
		};
		case User_Choice::print_2D_array:
		{
			if (my_matrix[0] != nullptr)
				print_2D_array(my_matrix, rows, columns);
			else
				cout << "An array is not initialized" << endl;
			break;
		};
		case User_Choice::exit:
		{
			end_of_program = true;
			break;
		}
		default: {};
		};
	};

	delete[] sorted_array;
	delete[] array_of_maxs;
	delete_2D_array(my_matrix, rows);

	return 0;
};

int32_t** array_keyboard_filling(const size_t rows, const size_t columns, const string& message)
{
	auto** array = new int32_t * [rows];

	for (size_t i = 0; i < rows; i++)
	{
		array[i] = new int32_t[columns];
		for (size_t j = 0; j < columns; j++)
		{
			cout << message;
			cin >> array[i][j];
		}
	}

	return array;
};

int32_t** array_random_filling(const size_t rows, const size_t columns)
{
	random_device rd;
	mt19937 gen(rd());

	const int32_t rand_min = -10;
	const int32_t rand_max = 20;

	uniform_int_distribution <> dis(rand_min, rand_max);

	auto** array = new int32_t * [rows];
	for (size_t i = 0; i < rows; i++)
	{
		array[i] = new int32_t[columns];
		for (size_t j = 0; j < columns; j++)
		{
			array[i][j] = dis(gen);
		};
	};

	return array;
};

bool is_negative(const int32_t number)
{
	return number < 0;
};

int32_t* create_1D_array_of_maxs(int32_t** array, const size_t rows, const size_t columns)
{
	int32_t* array_of_maxs = new int32_t[columns];

	for (size_t i = 0; i < columns; i++)
	{
		int32_t column_max = array[0][i];
		for (size_t j = 0; j < rows; j++)
		{
			if (array[j][i] > column_max)
				column_max = array[j][i];
		}
		array_of_maxs[i] = column_max;
	}
	return array_of_maxs;
}

int32_t* bubble_sort(int32_t* array, const size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
		for (size_t j = 0; j < size - 1; j++)
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
	return array;
}

int32_t* create_sorted_1D_array(int32_t** array, const size_t rows, const size_t columns)
{
	int32_t* sorted_array = new int32_t[rows * columns];

	for (size_t i = 0; i < rows * columns; i++)
		sorted_array[i] = array[i / columns][i % columns];

	return bubble_sort(sorted_array, rows * columns);
}

int32_t get_sum_of_negative_els(int32_t** array, const size_t rows, const size_t columns)
{
	int32_t sum_of_negative_els = 0;
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			if (is_negative(array[i][j]))
				sum_of_negative_els += array[i][j];
	return sum_of_negative_els;
}

void print_1D_array(int32_t* array, const size_t size)
{
	for (size_t i = 0; i < size; i++)
		cout << setw(5) << array[i];
}

void print_2D_array(int32_t** array, const size_t rows, const size_t columns)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			cout << setw(5) << array[i][j];
		};
		cout << '\n';
	};
	cout << endl;
};

void delete_2D_array(int32_t** array, const size_t rows)
{
	if (array == nullptr)
		return;
	for (size_t i = 0; i < rows; i++)
		delete[] array[i];
	delete[] array;
};

void delete_1D_array(int32_t* array)
{
	if (array == nullptr)
		return;
	delete[] array;
}