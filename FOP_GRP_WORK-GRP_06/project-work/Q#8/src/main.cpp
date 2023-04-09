#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

#define ERROR cin.clear(); \
			  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#define TAB "\t\t\t"



namespace params {
	enum {
		infant = 1,
		child,
		teenager,
		adult
	};
	std::string entry = "", ticketID, prsnCd;
	std::size_t pos;

	int tCnt = 0, tSales = 0, tInfnt = 0, tCld = 0, tTeen = 0, tAdlt = 0;

}	//namespace params

using std::cout; using std::cin; using std::getline;

int main() {

	cout << "Enter (FORMAT:TICKETNo_PRSNCode) or -1 TO EXIT AND DISPLAY THE OUTPUT\n"
		<< "eg: ODF023_2 or AER450_03, NOTE THAT TICKETNo must be of length 6 and Alphanumeric literal.\n";

input:
	while (true)
	{
		using namespace params;

		ticketID = ""; prsnCd = "";
		cin >> entry;

		//Exit
		if (entry == "-1") {
			break;
		}

		if (entry.size() < 8 || *(entry.begin() + 6) != '_') {
			cout << "ERROR: INCORRECT TICKET_NO, TRY AGAIN\n";
			ERROR
				continue;
		}

		//Parse
		char* str = &*entry.begin(), * iter;
		//ticketID
		for (iter = str; iter != str + 6; ++iter) {
			if (!std::isalnum(*iter)) {
				cout << "ERROR: INCORRECT TICKET_NO, TRY AGAIN\n";
				goto input;
			}
			ticketID += *iter;
		}
		//prsnCd
		for (iter += 1; *iter != '\0'; ++iter) { prsnCd += *iter; }

		try
		{
			std::stoi(prsnCd, &pos);
		}
		catch (const std::exception&)
		{
			cout << "ERROR: INVALID PERSON_CODE, TRY AGAIN\n";
			ERROR
				continue;
		}

		if (pos < prsnCd.size() || std::stoi(prsnCd) > adult || std::stoi(prsnCd) < infant) {
			cout << "ERROR: INVALID PERSON_CODE, TRY AGAIN\n";
			ERROR
				continue;
		}


		switch (std::stoi(prsnCd))
		{
		case infant:
			++tInfnt; tSales += 10;
			break;
		case child:
			++tCld; tSales += 5;
			break;
		case teenager:
			++tTeen; tSales += 20;
			break;
		case adult:
			++tAdlt; tSales += 20;
			break;
		default:
			break;
		}

		++tCnt;
	}


	//Displays total numbers of ppl & total amount of ticket sales, how many infants, childern, teenagers, adults
	cout << "\n" << TAB << "|TOTAL NO OF PEOPLE" << std::setw(38) << params::tCnt << "|\n"
		<< TAB << "|TOTAL AMOUNT OF TICKET SALES" << std::setw(28) << params::tSales << "|\n"
		<< TAB << "|NO OF INFANTS-01" << std::setw(40) << params::tInfnt << "|\n"
		<< TAB << "|NO OF CHILDREN-02" << std::setw(39) << params::tCld << "|\n"
		<< TAB << "|NO OF TEENAGERS-03" << std::setw(38) << params::tTeen << "|\n"
		<< TAB << "|NO OF ADULTS-04" << std::setw(41) << params::tAdlt << "|\n";

	ERROR
		cin.get();

	return 0;
}