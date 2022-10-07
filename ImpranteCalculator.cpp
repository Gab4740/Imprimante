#include <iomanip>
#include <conio.h>
#include <string>
#include <iostream>
#include "../Downloads/cvm 21.h"

using namespace std;

int main()
{
	char formatPapier, typeImpression, typePapier, aPerforer, typeFaconnage;	// Choix au clavier

	int nbOri, nbExe, nbImpR, nbImpRV, reste;	// Calcul a faire selon choix

	const double PRIX_8x11R = 31;				// 1000 feuilles 8.5x11 ou 8.5x14
	const double PRIX_8x11RV = 60;				// 1000 feuilles 8.5x11 ou 8.5x14 recto verso
	const double PRIX_11x17R = 61;				// 1000 feuilles 11x17 
	const double PRIX_11x17RV = 100;			// 1000 feuilles 11x17 recto verso 

	const double PRIX_PAPIER_1 = 20.50;			// Repros + gris
	const double PRIX_PAPIER_2 = 67.34;			// Rolland Evolution
	const double PRIX_PAPIER_3 = 122.94;		// Wausau royal

	const double PRIX_BROCHE = 0.03;			// Broche en coin
	const double PRIX_ENCOLLER = 0.6;			// Encollage avec ruban
	const double PRIX_TABLETTE = 0.35;			// Tablette pour document
	const double PRIX_DOSCHEVAL = 0.10;			// Broche a dos de cheval
	const double PRIX_PERFORER = 3;				// Perforer 1000 feuilles

	const double TPS = 0.05, TVQ = 0.09975;		// Taxes

	double coutR, coutRV, coutPapier, coutFaconnage, coutProduction, coutTotal;	// Resultat selon les choix

	int x = 37, y = 10, z = 35, a = 45;

	cout << left << setw(x) << "Nombre d'originaux" << ": ";
	cin >> nbOri;
	cout << setw(x) << "Nombre d'exemplaire \205 reproduire" << ": ";
	cin >> nbExe;

	cout
		<< "\n\n" << "Format du papier :" << endl << right
		<< setw(y) << "1." << " 8\253x11" << endl
		<< setw(y) << "2." << " 8\253x14" << endl
		<< setw(y) << "3." << left << setw(z) << " 11x17"
		<< "Votre choix : ";
	formatPapier = _getche();

	cout
		<< "\n\n" << left << "Type d'impression :" << endl << right
		<< setw(y) << "R." << " recto" << endl
		<< setw(y) << "V." << left << setw(z) << " recto - verso"
		<< "Votre choix : ";
	typeImpression = toupper(_getch());
	cout << char(toupper(typeImpression));

	switch (formatPapier)
	{
	case('1'):
	case('2'):
		if (typeImpression == 'R')
		{
			nbImpR = nbOri * nbExe;
			nbImpRV = 0;
		}
		else if (typeImpression == 'V')
			if (nbOri % 2 == 1)
			{
				nbImpR = nbExe;
				nbImpRV = (nbOri - 1) * nbExe / 2;
			}
			else
			{
				nbImpR = 0;
				nbImpRV = nbOri * (nbExe / 2);
			}
		coutR = nbImpR * PRIX_8x11R / 1000;
		coutRV = nbImpRV * PRIX_8x11RV / 1000;
		break;

	case('3'):
		if (typeImpression == 'R')
		{
			if (nbOri % 2 == 1)
				nbOri += 1;
			nbImpR = nbOri * (nbExe / 2);
			nbImpRV = 0;
		}
		else if (typeImpression == 'V')
		{
			reste = nbOri % 4;
			if (reste == 0)
			{
				nbImpR = 0;
				nbImpRV = nbOri * (nbExe / 4);
			}
			else if (reste == 1 || reste == 2)
			{
				nbImpR = nbExe;
				nbImpRV = (nbOri - reste) * nbExe / 4;
			}
			else if (reste == 3)
			{
				nbImpR = 0;
				nbImpRV = (nbOri + 1) * nbExe / 4;
			}
		}
		coutRV = nbImpRV * PRIX_11x17RV / 1000;
		coutR = nbImpR * PRIX_11x17R / 1000;
		break;
	}
	cout
		<< "\n\n"  << "Type de papier :"												<< endl << right
		<< setw(y) << "1."						<< " Repros + gris"						<< endl
		<< setw(y) << "2."						<< " Rolland \202volution glacier"		<< endl
		<< setw(y) << "3." << left << setw(z)	<< " Wausau royal, fibre texte \202tain"
		<< "Votre choix : ";
	typePapier = _getch();
	cout << typePapier;

	switch (typePapier)
	{
	case('1'):
		if (formatPapier == '1')
			coutPapier = ((nbImpR + nbImpRV) * (PRIX_PAPIER_1 / 1000)) / 2;
		else
			coutPapier = (nbImpR + nbImpRV) * (PRIX_PAPIER_1 / 1000);
		break;
	case('2'):
		if (formatPapier == '1')
			coutPapier = ((nbImpR + nbImpRV) * (PRIX_PAPIER_2 / 1000)) / 2;
		else 
			coutPapier = (nbImpR + nbImpRV) * (PRIX_PAPIER_2 / 1000);
		break;
	case('3'):
		if (formatPapier == '1')
			coutPapier = ((nbImpR + nbImpRV) * (PRIX_PAPIER_3 / 1000)) / 2;
		else
			coutPapier = (nbImpR + nbImpRV) * (PRIX_PAPIER_3 / 1000);
		break;
	}

	cout << "\n\n" << setw(a) << "Voulez-vous des documents perfor\202 ? (O/N)" << "Votre choix : ";
	aPerforer = toupper(_getch());

	if (aPerforer == 'N' || formatPapier == '3')
	{
		cout
			<< char(toupper(aPerforer))
			<< "\n\n" << "Type de fa\207onnage :"									<< endl << right
			<< setw(y) << "1."						<< " Broche en coin"			<< endl
			<< setw(y) << "2."						<< " Encoller avec ruban"		<< endl
			<< setw(y) << "3."						<< " Tablettes"					<< endl
			<< setw(y) << "4."						<< " Broche \205 dos de cheval" << endl
			<< setw(y) << "5." << left << setw(z)	<< " Aucun"
			<< "Votre choix : ";
		typeFaconnage = _getche();

		switch (typeFaconnage)
		{
			case('1'):
				coutFaconnage = nbExe * PRIX_BROCHE;
				break;
			case('2'):
				if (formatPapier == '1' || formatPapier == '2')
					coutFaconnage = nbExe * PRIX_ENCOLLER;
				else
					coutFaconnage = 0;
				break;
			case('3'):
				coutFaconnage = nbExe * PRIX_TABLETTE;
				break;
			case('4'):
				if (formatPapier == '3')
					coutFaconnage = nbExe * PRIX_DOSCHEVAL;
				else
					coutFaconnage = 0;
				break;
			case('5'):
				coutFaconnage = 0;
				break;
		}
		if (aPerforer == 'O')
			coutFaconnage = coutFaconnage + (nbImpR + nbImpRV) * (PRIX_PERFORER / 1000);
	}
	else if (aPerforer == 'O')
	{
		cout << aPerforer;
		coutFaconnage = (nbImpR + nbImpRV) * (PRIX_PERFORER / 1000);
	}

	cout << "\n\n\n" << "Appuyez sur une touche pour continuer ...";
	_getch();
	clrscr();

	coutProduction = coutR + coutRV + coutPapier + coutFaconnage;
	coutTotal = coutProduction + (coutProduction * TPS) + (coutProduction * TVQ);

	int b = 48, c = 10, d = 46;
	cout
		<< "\n\n\n" << "FACTURE" << "\n\n" << fixed << setprecision(2)
		<< left << setw(b)									<< "  Cout des impressions recto :"			<< right << setw(c) << coutR << " $"			<< endl
		<< left << setw(b)									<< "  cout des impressions recto-verso :"	<< right << setw(c) << coutRV << " $"			<< "\n\n"
		<< left << setw(b)									<< "  Cout du papier :"						<< right << setw(c) << coutPapier << " $"		<< endl
		<< left << setw(b)									<< "  Cout du faconnage :"					<< right << setw(c) << coutFaconnage << " $"	<< endl
		<< left << setw(b) << "  " << right << setw(c)		<< "------------"																			<< "\n\n"
		<< left << setw(b)									<< "  Cout de production :"					<< right << setw(c) << coutProduction << " $"	<< endl
		<< left << setw(b) << "  " << right << setw(c)		<< "============"																			<< "\n\n"
		<< "Cout total :" << right << setw(d) << coutTotal	<< " $";
	_getch();
}