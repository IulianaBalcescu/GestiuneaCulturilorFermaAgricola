#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<map>

using namespace std;

class ExceptieAfisare :public exception {
	string mesaj;
public:
	ExceptieAfisare(string mesaj) {
		this->mesaj = mesaj;
	}
	void afiseazaEroare() {
		cout << "EROARE DE AFISARE!!!!!" << endl;
		cout << this->mesaj << endl;
	}
};
class Cultura {
	const int id;
	string denumire;
	char* producator;
	float pret;
	int nrTerenuri;
	float* suprafata;
	static int contor;
public:

	//constructor fara parametrii
	Cultura() :id(contor++) {
		this->denumire = "Porumb";
		this->producator = new char[strlen("Andrei") + 1];
		strcpy(this->producator, "Andrei");
		this->pret = 0;
		this->nrTerenuri = 0;
		this->suprafata = nullptr;
	}
	Cultura(int id, string denumire, const char* producator, float pret,
		int nrTerenuri, float* suprafata) :id(contor++)
	{
		this->denumire = denumire;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
		this->pret = pret;
		this->nrTerenuri = nrTerenuri;
		this->suprafata = new float[this->nrTerenuri];
		for (int i = 0; i < this->nrTerenuri; i++) {
			this->suprafata[i] = suprafata[i];
		}
	}
	//constructor de copiere
	Cultura(const Cultura& c) :id(c.id) {
		this->denumire = c.denumire;
		this->producator = new char[strlen(c.producator) + 1];
		strcpy(this->producator, c.producator);
		this->pret = c.pret;
		this->nrTerenuri = c.nrTerenuri;
		this->suprafata = new float[this->nrTerenuri];
		for (int i = 0; i < this->nrTerenuri; i++) {
			this->suprafata[i] =c.suprafata[i];
		}
	}

	//destructor
	~Cultura()
	{
		if (this->producator != nullptr) {
			delete[]this->producator;
		}
		if (this->suprafata != nullptr) {
			delete[]this->suprafata;
		}
	}
	//operatorul =
	Cultura& operator=(const Cultura& c) {
		if (this != &c) {
			if (this->producator != nullptr) {
				delete[]this->producator;
			}
			if (this->suprafata != nullptr) {
				delete[]this->suprafata;
			}
			this->denumire = c.denumire;
			this->producator = new char[strlen(c.producator) + 1];
			strcpy(this->producator, c.producator);
			this->pret = c.pret;
			this->nrTerenuri = c.nrTerenuri;
			this->suprafata = new float[this->nrTerenuri];
			for (int i = 0; i < this->nrTerenuri; i++) {
				this->suprafata[i] = c.suprafata[i];
			}
			return *this;
		}
	}
	//geteri
	string getDenumire() {
		return this->denumire;
	}
	char* getProducator() {
		return this->producator;
	}
	float getPret() {
		return this->pret;
	}
	int getNrTerenuri() {
		return this->nrTerenuri;
	}
	float* getSuprafata() {
		return this->suprafata;
	}
	const int getId() {
		return this->id;
	}
	//seteri
	void setDenumire(string denumire) {
		this->denumire = denumire;
	}
	void setProducator(const char* producator) {
		if (this->producator != nullptr) {
			delete[]this->producator;
		}
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
	}
	void setPret(float pret) {
		this->pret = pret;
	}
	void setSuprafata(int nrTerenuri,float* suprafata) {
		if (this->suprafata != nullptr) {
			delete[] this->suprafata;
		}
		this->nrTerenuri = nrTerenuri;
		this->suprafata = new float[this->nrTerenuri];
		for (int i = 0; i < this->nrTerenuri; i++) {
			this->suprafata[i] = suprafata[i];
		}
	}
	//metode
	bool estePretulMaiMareDecat(float valoare) {
		if (this->pret < valoare) {
			return false;
		}
		else {
			return true;
		}
	}
	float suprafataTotala() {
		float total = 0;
		for (int i = 0; i < this->nrTerenuri; i++)
		{
			total += this->suprafata[i];
		}
		return total;
	}
	//1) media suprafetei
	float medie() {
		float medie = 0;
		float total=0;
		for (int i = 0; i < this->nrTerenuri; i++)
		{
			total += this->suprafata[i];
		}
		medie = total / this->nrTerenuri;
		return medie;
	}
	//2) minimul suprafetei
	float minim() {
		float minim = this->suprafata[0];
		for (int i = 0; i < this->nrTerenuri; i++) {
			if (this->suprafata[i] < minim) {
				minim = this->suprafata[i];
			}
		}
		return minim;
	}
	//3) maximul suprafetei
	float maxim() {
		float maxim = this->suprafata[0];
		for (int i = 0; i < this->nrTerenuri; i++) {
			if (this->suprafata[i] > maxim)
			{
				maxim = this->suprafata[i];
			}
		}
		return maxim;
	}
	//4) pretul exprimat in euro
	float Euro() {
		float euro = 0;
		euro = this->pret / 4.92;
		return euro;
	}
	void afisare() {
		cout << this->denumire << " " << this->producator << " " <<
			this->pret << " " << this->nrTerenuri << "  ";
		for (int i = 0; i < this->nrTerenuri; i++) {
			cout << this->suprafata[i] << ", ";
		}
	}
	//opeartori

	//operator +=(obiect + valoare)
	Cultura operator+=(int valoare) {
		this->pret += valoare;
		return *this;
	}
	//operatorul +=
	Cultura operator+=(Cultura c) {
		Cultura copie = *this; //apelam constructorul de copiere
		if (this->suprafata != nullptr) {
			delete[] this->suprafata;
		}
		this->nrTerenuri += c.nrTerenuri;
		this->suprafata = new float[this->nrTerenuri];
		for (int i = 0; i < copie.nrTerenuri; i++) {
			this->suprafata[i] = copie.suprafata[i];
		}
		for (int i = copie.nrTerenuri; i < this->nrTerenuri; i++) {
			this->suprafata[i] = c.suprafata[i - copie.nrTerenuri];
		}
		return *this;
	}
	//opratorul functie -operatorul ()
	float operator () () {
		float total = 0;
		for (int i = 0; i < this->nrTerenuri; i++)
		{
			total += this->suprafata[i];
		}
		return total;
	}
	virtual float operator()(float crestePret){
		this->pret += crestePret;
		return pret;
	}
	virtual int metoda() {
		return 1;
	}
	//operator cast
	explicit operator string() {
		return this->denumire;
	}
	explicit operator int() {
		return this->nrTerenuri;
	}
	explicit operator float() {
		float max = this->suprafata[0];
		for (int i = 0; i < this->nrTerenuri; i++) {
			if (max < this->suprafata[i])
				max = suprafata[i];
		}
		return max;
	}
	//operatorul de indexare
	float operator[] (int index) {
		if (index >= 0 && index < this->nrTerenuri) {
			return this->suprafata[index];
		}
		else
		{
			throw new exception("Pozitia indexului nu se regaseste in vector!");
		}
	}
	//operator <<
	friend ostream& operator<<(ostream& out, const Cultura& c) {
		out << "Id-ul culturii: " << c.id << endl;
		out << "Denumirea culturii: " << c.denumire << endl;
		out << "Producatorul este: " << c.producator << endl;
		out << "Pretul culturii este: " << c.pret << endl;
		out << "Numarul de terenuri cultivate este: " << c.nrTerenuri << endl;
		out << "Suprafata terenuri: ";
		for (int i = 0; i < c.nrTerenuri; i++) {
			out << c.suprafata[i] << " | ";
		}
		out << endl;
		out << "Contorul culturii este: " << c.contor << endl;
		return out;
	}
	//operator >>
	friend istream& operator>>(istream& in, Cultura& c) {
		cout << "Denumirea: ";
		in >> ws;
		getline(in, c.denumire);
		cout << "Numele producatorului este: ";
		in >> ws;
		delete[]c.producator;
		char aux[50];
		in.getline(aux, 49);
		c.producator = new  char[strlen(aux) + 1];
		strcpy(c.producator, aux);

		cout << "Pretul este: ";
		in >> c.pret;

		cout << "Numarul de terenuri ";
		in >> c.nrTerenuri;
		delete[]c.suprafata;
		cout << "Suprafata terenurilor: ";
		c.suprafata = new float[c.nrTerenuri];
		for (int i = 0; i < c.nrTerenuri; i++) {
			in >> c.suprafata[i];
		}
		return in;
	}
	//citirea si scrierea in fisier

	//operator <<
	friend ofstream& operator<<(ofstream& out, const Cultura& c) {
		out << c.denumire << endl;
		out << c.producator << endl;
		out << c.pret << endl;
		out << c.nrTerenuri << endl;

		for (int i = 0; i < c.nrTerenuri; i++) {
			out << c.suprafata[i] << endl;
		}
		return out;
	}
	//operator >>
	friend ifstream& operator>>(ifstream& in, Cultura& c) {
		
		in >> ws;
		getline(in, c.denumire);
		in >> ws;
		delete[]c.producator;
		char aux[50];
		in.getline(aux, 49);
		c.producator = new  char[strlen(aux) + 1];
		strcpy(c.producator, aux);

		in >> c.pret;
		in >> c.nrTerenuri;
		delete[]c.suprafata;
		c.suprafata = new float[c.nrTerenuri];
		for (int i = 0; i < c.nrTerenuri; i++) {
			in >> c.suprafata[i];
		}
		return in;
	}
	virtual string tipClasa() {
		return "Clasa de baza!";
	}
};
int Cultura::contor = 1;

class CulturaSezoniera :public Cultura
{
	string ingrasemant;
	bool esteDeVara;
public:
	CulturaSezoniera() :Cultura() {
		this -> ingrasemant = "Anonim";
		this->esteDeVara = false;
	}
	CulturaSezoniera(int id,string denumire, const char* producator, float pret,
		int nrTerenuri, float* suprafata, string ingrasemant, bool esteDeVara) :Cultura(id,denumire, producator, pret, nrTerenuri, suprafata) {
		this->ingrasemant = ingrasemant;
		this->esteDeVara = esteDeVara;
	}
	//constructor de copiere
	CulturaSezoniera(const CulturaSezoniera& cz) :Cultura(cz) {
		this->ingrasemant = cz.ingrasemant;
		this->esteDeVara = cz.esteDeVara;
	}
	~CulturaSezoniera() {

	}
	CulturaSezoniera& operator=(const CulturaSezoniera& cz) {
		Cultura::operator=(cz);
		this->ingrasemant = cz.ingrasemant;
		this->esteDeVara = cz.esteDeVara;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const CulturaSezoniera& cz) {
		out << (Cultura&)cz;
		out << "ingrasemantul utilizat este: " << cz.ingrasemant << endl;
		out << "Cultura se cultiva vara(1-Da sau 0-Nu): " << cz.esteDeVara << endl;
		return out;
	}

	void afisare() {
		Cultura copie = *this;
		copie.afisare();
		cout << "Ingrasemantul utilizat este: " << ingrasemant << endl;
		cout << "Cultura se cultiva vara(1-Da sau 0-Nu): " << esteDeVara << endl;
	}
	int metoda() {
		return 100;
	}
	string tipClasa() {
		return "Clasa derivata!";
	}

};

class Ferma
{
	string numeFerma;
	int nrCulturi;
	Cultura** culturi;
public:
	Ferma() {
		this->numeFerma = "Anonim";
		this->nrCulturi = 0;
		this->culturi = nullptr;
	}
	Ferma(string numeFerma, int nrCulturi, Cultura** culturi) {
		this->numeFerma = numeFerma;
		this->nrCulturi = nrCulturi;
		this->culturi = new Cultura * [this->nrCulturi];
		for (int i = 0; i < this->nrCulturi; i++) {
			this->culturi[i] = new Cultura(*culturi[i]);
		}
	}

	Ferma(const Ferma& f) {
		this->numeFerma = f.numeFerma;
		this->nrCulturi = f.nrCulturi;
		this->culturi = new Cultura * [this->nrCulturi];
		for (int i = 0; i < this->nrCulturi; i++) {
			this->culturi[i] = new Cultura(*f.culturi[i]);
		}
	}
	~Ferma() {
		for (int i = 0; i < this->nrCulturi; i++) {
			delete this->culturi[i];
		}
		delete[]this->culturi;
	}

	Ferma& operator= (const Ferma& f) {
		if (this != &f) {
			for (int i = 0; i < this->nrCulturi; i++) {
				delete this->culturi[i];
			}
			delete[]this->culturi;
			this->numeFerma = f.numeFerma;
			this->nrCulturi = f.nrCulturi;
			this->culturi = new Cultura * [this->nrCulturi];
			for (int i = 0; i < this->nrCulturi; i++) {
				this->culturi[i] = new Cultura(*f.culturi[i]);
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Ferma& f) {
		out << "Nume ferma: " << f.numeFerma << endl;
		out << "Numar culturi: " << f.nrCulturi << endl;
		out << "---------Culturi---------" << endl;
		for (int i = 0; i < f.nrCulturi; i++) {
			out << *f.culturi[i] << endl;
		}
		out << "-------------------------" << endl;
		return out;
	}


	void adaugaCultura(Cultura c) {
		Ferma copie = *this;
		for (int i = 0; i < this->nrCulturi; i++) {
			delete this->culturi[i];
		}
		delete[]this->culturi;
		this->nrCulturi++;
		this->culturi = new Cultura * [this->nrCulturi];
		for (int i = 0; i < copie.nrCulturi; i++) {
			this->culturi[i] = new Cultura(*copie.culturi[i]);
		}
		this->culturi[this->nrCulturi - 1] = new Cultura(c);
	}
	void adaugaCultura() {
		Ferma copie = *this;
		for (int i = 0; i < this->nrCulturi; i++) {
			delete this->culturi[i];
		}
		delete[]this->culturi;
		this->nrCulturi++;
		this->culturi = new Cultura * [this->nrCulturi];
		for (int i = 0; i < copie.nrCulturi; i++) {
			this->culturi[i] = new Cultura(*copie.culturi[i]);
		}
		this->culturi[this->nrCulturi - 1] = new Cultura(*this->culturi[this->nrCulturi - 2]);
	}

	Ferma& operator+=(Cultura c) {
		adaugaCultura(c);
		return*this;
	}
	Ferma& operator+=(Ferma f) {
		adaugaCultura();
		return*this;
	}
};

template <typename clasa>
class Gestiune {
	int nrObj;
	clasa* obiecte;
public:
	Gestiune() {
		this->nrObj = 0;
		this->obiecte = NULL;
	}
	Gestiune(int nrObj, clasa* obiecte) {
		this->nrObj = nrObj;
		this->obiecte = new clasa[this->nrObj];
		for (int i = 0; i < this->nrObj; i++) {
			this->obiecte[i] = obiecte[i];
		}
	}
	Gestiune(const Gestiune& g) {
		this->nrObj = g.nrObj;
		this->obiecte = new clasa[this->nrObj];
		for (int i = 0; i < this->nrObj; i++) {
			this->obiecte[i] = g.obiecte[i];
		}
	}

	friend ostream& operator<<(ostream& out, const Gestiune& g) {
		out << "nr: " << g.nrObj << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		for (int i = 0; i < g.nrObj; i++) {
			out << g.obiecte[i] << endl;
		}
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		return out;
	}

	void adaugaObiect(clasa obj) {
		Gestiune copie = *this;
		delete[]this->obiecte;
		nrObj++;
		this->obiecte = new clasa[this->nrObj];
		for (int i = 0; i < copie.nrObj; i++) {
			this->obiecte[i] = copie.obiecte[i];
		}
		this->obiecte[this->nrObj - 1] = obj;
	}
};
void main() 
{
	Cultura c1;
	cout << "................GETTERI:.................." << endl;
	Cultura c2(2,"grau", "Andrei", 11.5, 5, new float[5]{ 120,230,340,543,123 });
	cout << c2.getId() << endl;
	cout << c2.getDenumire() << endl;
	cout << c2.getProducator() << endl;
	cout << c2.getPret() << endl;
	cout << c2.getNrTerenuri() << endl;
	for (int i = 0; i < c2.getNrTerenuri(); i++) {
		cout << c2.getSuprafata()[i] << " ";
	}
	cout << endl;
	Cultura c3(3, "Floarea-soarelui", "Ionescu Andrei", 12,4, new float[4]{ 100, 50.5,230, 45.7 });
	Cultura c4(4, "Grau", "Popescu Ion", 8, 3, new float[3]{ 120, 150,250 });
	cout << ".................SETTERI....................." << endl;
	c2.setDenumire("Ovaz");
	c2.setProducator("Popescu Ion");
	try {
		c2.setProducator("Popescu Ion");
	}
	catch (exception *e){
		cout << e->what() << endl;
	}
	c2.setPret(5.2);
	c2.setSuprafata(2, new float[2]{ 110,50.6 });
	try {
		c2.setSuprafata(2, new float[2]{ 110,50.6 });

	}
	catch (ExceptieAfisare e) {
		e.afiseazaEroare();
	}
	cout << c2.getId() << endl;
	cout << c2.getDenumire() << endl;
	cout << c2.getProducator() << endl;
	cout << c2.getPret() << endl;
	cout << c2.getNrTerenuri() << endl;
	for (int i = 0; i < c2.getNrTerenuri(); i++) {
		cout << c2.getSuprafata()[i] << " ";
	}
	cout << ".................METODE:..........." << endl;
	if (c2.estePretulMaiMareDecat(6.5))
	{
		cout << "Pretul la " <<c2.getDenumire()<<"  este mai mare!" << endl;
	}
	else {
		cout << "Pretul  la " << c2.getDenumire() << "  este mai mic!" << endl;
	}
	cout << c2.suprafataTotala() << endl;
	cout << "........................Operator +=............................" << endl;
	c1.afisare();
	c1 += 10;
	c1.afisare();
	cout << endl;
	float suprafete1[]{ 120, 54,82 };
	Cultura c5(5, "Rapita", "Cristian Stefan", 11.2, 3, suprafete1);
	c3 += c5;
	c3.afisare();
	cout << endl;
	cout << "Operatorul functie (operator () )" << endl;
	cout << c3() << endl;
	cout << c3(3.3) << endl;
	cout << endl << ".............Operator cast........" << endl;
	string val = (string)c3;
	cout << val << endl;
	int val1 = (int)c3;
	cout << val1 << endl;
	float maxim = (float)c3;
	cout << maxim << endl;
	cout << endl << "..........Operator de indexare (operator [] )......." << endl;
	cout << c3[5] << endl;
	try {
		cout << c3[5] << endl;
	}
	catch(exception *ex){
		cout << ex->what() << endl;
	}
	cout << c3 << endl << endl;
	cout << "........Operator  <<............." << endl;
	cout << c4 << endl;
	cout << "..........Operator >>............." << endl << endl;;
	/*cout << c1 << endl;
	cin >> c1;
	cout << endl << endl;
	cout << c1 << endl;*/
	cout << ".........CITIREA SI SCRIEREA IN FISIER............" << endl;
	ofstream file("culturi.txt", ios::out);
	file << c4 << endl;
	cout << "S-a scris in fiserul text!" << endl;
	file.close();
	cout <<"..........CITIRE DIN FISIER.................."<< endl;

	Cultura cText;
	ifstream gfile("culturaDus.txt", ios::in);
	if (gfile.is_open()) {
		gfile >> cText;
		gfile.close();
	}
	else {
		cout << "Fisierul cautat nu exista!" << endl;
	}

	cout << cText << endl;
	cout << endl << endl << endl;

	cout << "............	MOSTENIRE	..............." << endl;
	CulturaSezoniera cz1;
	cout << cz1 << endl << endl;
	CulturaSezoniera cz2(2, "Orz", "Stefan Petre", 12, 3, new float[3]{ 120,59.79,130 }, "Ingrasemant cu potasiu", 1);
	cout << cz2 << endl << endl;

	cout << "-----------VIRTUALIZAREA -----------" << endl;
	cout << c5.tipClasa() << endl;
	cout << cz2.tipClasa() << endl;
	cout << "............		COMPUNERE	..............." << endl << endl;
	Ferma f;
	cout << f << endl;

	Cultura* vectorCulturiPtFerma[3];
	vectorCulturiPtFerma[0] = &c3;
	vectorCulturiPtFerma[1] = &c5;
	vectorCulturiPtFerma[2] = &cz2;

	Ferma f1("Alpha SRL", 3, vectorCulturiPtFerma);
	cout << f1 << endl;

	Ferma f2 = f;
	cout << f2 << endl;

	f2 = f1;
	cout << f2 << endl;

	f2.adaugaCultura(c4);
	f2 += c4;
	cout << f2 << endl;

	cout << endl << endl;
	cout << "----------- CLASE TEMPLATE -----------" << endl;
	Gestiune<Cultura> gestProd(2, new Cultura[2]{ c3,cz1 });
	cout << gestProd << endl;
	gestProd.adaugaObiect(c3);
	cout << gestProd << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	Gestiune<int> gestInt(2, new int[2]{ 2,1 });
	cout << gestInt << endl;
	gestInt.adaugaObiect(5);
	cout << gestInt << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	Gestiune<Ferma> gestFerma(2, new Ferma[2]{ f1,f });
	cout << gestFerma << endl;
	gestFerma.adaugaObiect(f2);
	cout << gestFerma << endl;
	cout << endl << endl << endl;
	cout << "----------- STL(Standard Template Library) -----------" << endl;
	Cultura cultura1(5, "Orez", "Ana Maria", 20, 3, new float[3]{ 50,110,90 });
	Cultura cultura2(6, "Pepene-Rosu", "Sanziana Mihai", 5, 3, new float[3]{ 50,90,150 });
	Cultura cultura3(7, "Lavanda", "Crina Florea", 25, 2, new float[2]{ 150,110});
	Cultura cultura4(8, "Rosii", "Andrei Oprea", 8, 4, new float[4]{ 50,200,190,80 });
	Cultura cultura5(9, "Cartofi", "Ion Popa", 5, 3, new float[3]{ 250,110,290 });
	cout << "VECTOR" << endl;
	vector<Cultura> vectorCulturaSTL;
	vectorCulturaSTL.push_back(cultura1);
	vectorCulturaSTL.push_back(cultura2);
	vectorCulturaSTL.push_back(cultura3);
	vectorCulturaSTL.push_back(cultura4);
	vectorCulturaSTL.push_back(cultura5);
	for (int i = 0; i < vectorCulturaSTL.size(); i++) {
		cout << vectorCulturaSTL[i] << endl;
	}
	cout << endl << endl << "DUPA POP_BACK" << endl;
	vectorCulturaSTL.pop_back();
	vector<Cultura>::iterator vit;
	for (vit = vectorCulturaSTL.begin(); vit != vectorCulturaSTL.end(); vit++) {
		cout << *vit << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << "LIST" << endl;
	list<Cultura> listCulturaSTL;
	listCulturaSTL.push_back(cultura1);
	listCulturaSTL.push_back(cultura2);
	listCulturaSTL.push_back(cultura3);
	listCulturaSTL.push_back(cultura4);
	listCulturaSTL.push_back(cultura5);

	list<Cultura>::iterator lit;
	for (lit = listCulturaSTL.begin(); lit != listCulturaSTL.end(); lit++) {
		cout << *lit << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << "...............Map.........................." << endl;
	map<int, Cultura> mapCulturaSTL;
	mapCulturaSTL.insert(pair<int, Cultura>(cultura1.getNrTerenuri(), cultura1));
	mapCulturaSTL.insert(pair<int, Cultura>(cultura2.getNrTerenuri(), cultura2));
	mapCulturaSTL.insert(pair<int, Cultura>(cultura3.getNrTerenuri(), cultura3));
	mapCulturaSTL.insert(pair<int, Cultura>(cultura4.getNrTerenuri(), cultura4));
	mapCulturaSTL.insert(pair<int, Cultura>(cultura5.getNrTerenuri(), cultura5));


	map<int, Cultura>::iterator mit;
	for (mit = mapCulturaSTL.begin(); mit != mapCulturaSTL.end(); mit++) {
		cout << mit->first << endl;
		cout << mit->second << endl;
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << endl << endl << endl;

}