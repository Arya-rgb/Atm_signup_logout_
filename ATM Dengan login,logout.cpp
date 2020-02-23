#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

class mesinatm {
	public:
	void BuatAkunBaru(string newusername, string newpassword);
	void loginakun(string loginusername, string loginpassword);
	void deposituang(double depositAmount);
	void penarikanuang(double penarikanAmount);
	void setloginakun(int setlokasiakun);
	void setpergerakanuangterakhir(int IDakun, double amount);
	void settotaluangpertama(int IDakun);
	void setoprasiterakhir(int IDakun, char userinput);
	void menuakun();
	int Getloginakun() const;
	double Getpergerakanuangterakhir(int IDakun) const;
	double GetTotaluangakun(int IDakun) const;
	double Gettotaluangakunpertama(int IDakun) const;
	char Getoprasiterakhir(int IDakun) const;
	string Getusername(int IDakun) const;
	
	private:
	int terloginlokasiakun;
	double totaluangakun;
	double totaluangakunpertama;
	double pergerakanuangterakhir;
	char oprasiterakhir;
	string username;
	string password;	
};

mesinatm akun;

vector<mesinatm> daftarakun;

void menuakun();
void usermenu();

void mesinatm:: setloginakun(int setlokasiakun) {
	terloginlokasiakun = setlokasiakun;
	return;		
}
int mesinatm::Getloginakun() const {
	return terloginlokasiakun;
}

void mesinatm::BuatAkunBaru(string newusername, string newpassword) {
	
	int ukurandaftarakun = daftarakun.size();
	
	daftarakun.at(ukurandaftarakun - 1).totaluangakun = 0.0;
	daftarakun.at(ukurandaftarakun - 1).username = newusername;
	daftarakun.at(ukurandaftarakun - 1).password = newpassword;
	
		
}

void mesinatm::loginakun(string loginusername, string loginpassword) {
	
	int ukurandaftarakun = daftarakun.size();
	bool berhasillogin = false;
	int lokasiakun = 0;
	
	for(int i = 0; i < ukurandaftarakun; i++) {
	
		if(loginusername == daftarakun.at(i).username) {
		
			if(loginpassword == daftarakun.at(i).password){
			
				berhasillogin = true;
				lokasiakun = i;
			}
			
		}
	}
	if(berhasillogin !=true) {
		cout<<endl<<"login gagal !"<<endl<<endl;
		usermenu();	
	}
	
	
	else if(berhasillogin == true) {
		
		setloginakun(lokasiakun);
		cout<<endl<<"akses diberikan --> "<< daftarakun.at(terloginlokasiakun).username<<endl;
		menuakun();
		
	}
	
	return;
		
}

void mesinatm::deposituang(double depositAmount) {
	
	daftarakun.at(terloginlokasiakun).totaluangakun += depositAmount;
	return;
	
}

void mesinatm::penarikanuang(double penarikanAmount) {
	
	daftarakun.at(terloginlokasiakun).totaluangakun -=  penarikanAmount;
	
	return; 
}

double mesinatm::GetTotaluangakun(int IDakun) const {
	return daftarakun.at(terloginlokasiakun).totaluangakun;
	
}

void mesinatm::setpergerakanuangterakhir(int IDakun, double amount) {
	
	daftarakun.at(IDakun).pergerakanuangterakhir = amount;
		
}

void mesinatm::settotaluangpertama(int IDakun) {
	
	daftarakun.at(IDakun).totaluangakunpertama = daftarakun.at(terloginlokasiakun).totaluangakun;
	
}

void mesinatm::setoprasiterakhir(int IDakun, char userinput) {
	
	daftarakun.at(IDakun).oprasiterakhir = userinput;
	
}

double mesinatm::Getpergerakanuangterakhir(int IDakun) const {

return daftarakun.at(IDakun).pergerakanuangterakhir;

}

double mesinatm::Gettotaluangakunpertama(int IDakun) const {

return daftarakun.at(IDakun).totaluangakunpertama;

}

char mesinatm::Getoprasiterakhir(int IDakun) const {

return daftarakun.at(IDakun).oprasiterakhir;

}

string mesinatm::Getusername(int IDakun) const {

return daftarakun.at(Getloginakun()).username;

}

void usermenu() { 
	
	char pilihanuser;
	string membuatiduser;
	string membuatpassworduser;
	string usernamecheck;
	string passwordcheck;
	
	cout <<"1 --> login"<<endl;
	cout <<"2 --> membuat akun baru"<<endl;
	cout <<"3 --> keluar"<<endl<<endl<<">";
	cin >> pilihanuser;
	
	if((pilihanuser == '1') || (pilihanuser == '!')) {
		
		cout << endl << "masukan nama = "<<endl;
		cin  >> usernamecheck;
		cout << "masukan password = "<<endl;
		cin  >> passwordcheck;
		
		akun.loginakun(usernamecheck, passwordcheck);
	}
	
	else if((pilihanuser == '2') || (pilihanuser == '@')) {
		
		cout << endl << "masukan nama baru = "<<endl;
		cin  >> membuatiduser;
		cout << "masukan password baru = "<<endl;
		cin  >> membuatpassworduser;
		
		daftarakun.push_back(akun);
		
		akun.BuatAkunBaru(membuatiduser, membuatpassworduser);
		
		cout << endl << "terimakasih telah menggunakan jasa kami, akun anda telah di buat!"<<endl<<endl;
		 
		usermenu();
	}
	
	else if((pilihanuser == '3') || (pilihanuser == '#')){
		cout << endl << "anda telah keluar !" <<endl<<endl;
		
	}
	
	else {
		
		cout << endl << "masukan perintah yang benar !" << endl;
		usermenu ();
	}
	
	return;
}

void mesinatm::menuakun() {
	
	char masukanuser;
	double amountdarideposit;
	double amountdaripenarikan;
	
	cout << endl << "a --> deposito uang"<<endl;
	cout <<"b --> penarikan uang"<<endl;
	cout <<"c --> lihat total uang sekarang"<<endl;
	cout <<"d --> Logout"<<endl;
	cout <<"e --> keluar "<<endl;
	cout <<endl<<">";
	cin  >>masukanuser;
	
	if((masukanuser == 'a') || (masukanuser == 'A')) {
		
		settotaluangpertama(Getloginakun());
		cout << endl << "Jumlah uang = "<<endl;
		cin  >> amountdarideposit;
		setpergerakanuangterakhir(Getloginakun(), amountdarideposit);
		setoprasiterakhir(Getloginakun(), masukanuser);
		deposituang(amountdarideposit);
		menuakun();		
	}
	
	else if((masukanuser == 'b') || (masukanuser == 'B')) {
		
		cout << endl << "Besar uang yang di tarik = "<<endl;
		cin  >> amountdaripenarikan;
		
		if(amountdaripenarikan > GetTotaluangakun(Getloginakun())) {
			
			cout << endl << "dana tidak mencukupi :("<<endl;
			
		}
		
		else {
		
		settotaluangpertama(Getloginakun());
		setpergerakanuangterakhir(Getloginakun(), amountdaripenarikan);
		setoprasiterakhir(Getloginakun(), masukanuser);
		penarikanuang(amountdaripenarikan);
		
		menuakun();
		}
		
	}
	
	else if((masukanuser == 'c')  ||  (masukanuser == 'C')) {
		
		cout << endl <<"total uang pertama = RP."<<fixed<<setprecision(2)<<Gettotaluangakunpertama(Getloginakun())<<endl;
		
		if(Getoprasiterakhir(Getloginakun()) == 'd') {
			
			cout << "Jumlah deposit = RP." << fixed << setprecision(2)<<Getpergerakanuangterakhir(Getloginakun())<<endl;
			
		}
		
		else if(Getoprasiterakhir(Getloginakun()) == 'b') {
			
			cout << " jumlah penarikan = RP."<<fixed<<setprecision(2)<<Getpergerakanuangterakhir(Getloginakun())<<endl;
			
		}
		
		cout << "total uangmu = RP." << fixed << setprecision(2) <<GetTotaluangakun(Getloginakun())<<endl;
		
		menuakun();		
	}
	
	
	else if ((masukanuser == 'd') || (masukanuser == 'D')) {
		
		cout << endl <<"Terimakasih telah menggunakan jasa Kelompok 1 tuan " <<Getusername(Getloginakun())<<"!"<<endl<<endl;
		
		usermenu();
	}
	
	else {
		
		cout << "pilihan tidak ada ERROR !"<<endl;
		
		usermenu();
		
	}
	
	return;
}

//untuk menu atas 

int main () {
	

	cout << "____________________________________________________________________"<<endl;
	cout << "                                                                    "<<endl;
	cout << "Selamat datang Di ATM AMAN dari daryapcoy"<<endl<<endl;
	cout << "silahkan pilih menu di bawah ini:"<<endl<<endl;
	
	usermenu();
}
