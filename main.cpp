/**
 *  Micheál Carroll
 *  C00218621
 *  Ex_7
 *  Cart and Pol calculator
 */


/**< preprocessor directives */
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cmath>


using namespace std;

/**< main function */
int main(void)
{
    /**< variable declarations */
    char input;

    /**< function prototypes */
    char menu(void);
    void cart2Pol(void);
    void pol2Cart(void);

	cout << "Conversion between Polar and Cartesian Coordinates\n" << endl;

	do
	{
	    input = menu();

		switch (input)
		{
			case 'p':   cart2Pol();
						break;

			case 'c':   pol2Cart();
						break;

			case 'q':   cout << "\nGoodbye...\n" << endl;
						break;

			default:	cout << "\nInvalid input, try again...\n" << endl;

						getchar();
						getchar();
						break;
		}
	}
	while (input != 'q');

	return 0;
}


char menu(void)
{
    char choice;

    cout << "\n Choose from the following: " <<
            "\n Press p for Cartesian to Polar " <<
            "\n Press c for Polar to Cartesian " <<
            "\n Press q to quit program \n \t";

    cin >> choice;

    return choice;
}


void cart2Pol(void)
{
    /**< variable declarations */
    double x, y, mag, angle;
    double *magPtr = &mag, *anglePtr = &angle;

    /**< function prototype */
    void cart2PolCalc(double, double, double *, double *);

    cout << "\n Cartesian to Polar...\n" << endl;

    //Enter a value for x
    cout << "\n Enter x: " << endl;
    cin >> x;

    //Enter a value for y
    cout << "\n Enter y: " << endl;
    cin >> y;

    cart2PolCalc(x, y, magPtr, anglePtr);

    cout << mag << " < " << angle << endl;

    return;
}


void cart2PolCalc(double xVal, double yVal, double *mPtr, double *aPtr)
{
    *mPtr = sqrt( xVal * xVal + yVal * yVal );
    *aPtr = atan2(yVal, xVal) / M_PI * 180.0;
}


void pol2Cart(void)
{
    double x, y, mag, angle;
    double *xPtr = &x, *yPtr = &y;

    /**< function prototype */
    void pol2CartCalc(double mag, double angle, double *XPtr, double *YPtr);

    cout << "\n Polar to Cartesian...\n" << endl;

    cout << "\n Enter mag: " << endl;
    cin >> mag;
    cout << "\n Enter angle (r): " << endl;
    cin >> angle;

    pol2CartCalc(mag, angle, xPtr, yPtr);

    cout << x << ", " << y << endl;

    return;
}


void pol2CartCalc(double mag, double angle, double *XPtr, double *YPtr)
{
    *XPtr = (mag*cos(angle * M_PI / 180.0));
    *YPtr = (mag*sin(angle * M_PI / 180.0));
}
