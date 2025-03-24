/*define a function that creates and returns a Movie object, then display it 
using the overloaded stream insertion operator, while also ensuring user input 
validation. The Movie object will use a nested struct for additional movie details.

requirement:
Repo: public
make sure that your structs should include at least 3 different data type*/


#include <iostream>
#include <string>

using namespace std;

// Movie struct including nested struct
struct Movie {
	struct Details {
		int releaseYear;
		int releaseMonth;
		int releaseDay;
	} details;
	string Title;
	string Director;
	bool isAdult;
};


// Overloading of << operator (this was so hard for me to figure out, idk why)
ostream& operator<<(ostream& os, const Movie& m) {
	os << "Title: " << m.Title << '\n'
		<< "Director: " << m.Director
		<< "\nRelease date: " << m.details.releaseMonth << "/" << m.details.releaseDay << "/" << m.details.releaseYear
		<< "\nAdult rating? " << m.Title << " is " << (m.isAdult ? "" : "not ") << "adult rated.";
		return os;
}

// Movie input function
void getMovieInput(Movie& m) {
	cout << "Enter movie title: \n";
	getline(cin, m.Title);

	cout << "Enter movie director: \n";
	getline(cin, m.Director);


	// Get date, validates input
		// Year
	bool validDate = 0;
	while (!validDate) {
		cout << "Enter release year: ";
		cin >> m.details.releaseYear;
		if (m.details.releaseYear > 0) {
			validDate = 1;
		}
		else {
			cout << "Invalid year. Please enter a valid year. \n";
		}
	}

		// Month
	validDate = 0;
	while (!validDate) {
		cout << "Enter release month (1-12): ";
		cin >> m.details.releaseMonth;
		if (m.details.releaseMonth >= 1 && m.details.releaseMonth <= 12) {
			validDate = 1;
		}
		else {
			cout << "Invalid month. Please enter a valid month (1-12).\n";
		}
	}

		// Day
	validDate = 0;
	while (!validDate) {
		cout << "Enter release day (1-31): ";
		cin >> m.details.releaseDay;
		if (m.details.releaseDay >= 1 && m.details.releaseDay <= 31) {
			validDate = 1;
		}
		else {
			cout << "Invalid day. Please enter a valid day (1-31).\n";
		}
	}

	// Adult rating, validates input
	char adultRating;
	bool validRating = 0;
	while (!validRating) {
		cout << "Is the movie adult rated? (y/n): ";
		cin >> adultRating;
		if (adultRating == 'y' || adultRating == 'Y') {
			m.isAdult = 1;
			validRating = 1;
		}
		else if (adultRating == 'n' || adultRating == 'N') {
			m.isAdult = 0;
			validRating = 1;
		}
		else {
			cout << "Invalid input. Please enter 'y' or 'n' only.\n";
		}
	}
}

int main() {
	Movie myMovie;

	getMovieInput(myMovie);

	cout << '\n' << "Movie details: " << "\n\n"
		<< myMovie;


	return 0;
}
