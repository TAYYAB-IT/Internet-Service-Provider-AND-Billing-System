#include<iostream>
#include<conio.h>
#include<string.h>
#include<cstdlib>
#include<windows.h>
#include<iomanip>
#include<ctime>
using namespace std;
	void tab1() {
	for (int i = 0; i < 73; i++) {
		cout << " ";
	}}
int x,y,z;
char ch;
class Employee;
class Manager;
class Accounts;
class Acc_Transactions;
struct transaction{
	 char *date_time; 
	 float req_amount;
	 string trans_type;
	 float new_amount;
};
struct transaction_node{
     transaction trans_data;
	 transaction_node *next_trans;
};
class transaction_stack{
	private:
		transaction_node *top;
	public:
		transaction_stack():top(NULL){}
		friend class Accounts;
		friend class Employee;
};
///////////Accounts///////////////////////
struct Account_PD{
		string name;
		long long int Account_No;
		string password;
		int age;
		string city;
		string phone;
		string cnic;
		string email;
	    float amount;
	    transaction_stack acc_trans;
};
struct Account_node{
	Account_PD  acc_data;
	Account_node  *next_acc;
};
//////////////Account//////////////////
class Accounts{
	public:
	Account_node *first_acc;
	Account_node *last_acc;
	int acc_length;
	Account_node *acc_currunt;
Accounts():first_acc(NULL),last_acc(NULL),acc_length(0),acc_currunt(NULL){}		
bool Account_Login();
void profile();
void deposit();
void withdraw();
void transaction_history();
void reset_pass();
};
Accounts acc;
///////////Account login//////////////////
bool Accounts::Account_Login(){
			int temp;
			Account_node *tttt=new Account_node;
			tttt=acc.first_acc;
			long long int id;
			bool chk;
			string t,star;				
			lable:
	temp = 0;
	t= "";
				system("cls");
	cout << "\n\n\n\n\n";
	cout <<"\t\t\t\t\t\t\t" << setw(30) << "Log in"<<setw(40);
	cout << "\n\t\t\t\t\t\t\t" << setw(70);
	cout << "\n\t\t\t\t\t\t\t" << setw(88);
	cout << "\n\n\n\t\t\t\t\t\t\tAccount No.::";
	cin>>id;
	lable2:
				system("cls");
	cout << "\n\n\n\n\n";
	cout <<"\t\t\t\t\t\t\t" << setw(30) << "Log in"<<setw(40);
	cout << "\n\t\t\t\t\t\t\t" << setw(70);
	cout << "\n\t\t\t\t\t\t\t" << setw(88);
	cout << "\n\n\n\t\t\t\t\t\t\tAccount No.::"<<id;
	cout << "\n\n\n\t\t\t\t\t\t\tPassword(space will be neglected automatically)::";
	cout<<star;
	ch = '1';
	while (1) {
		ch = getch();
		if (ch != 13) {
			if (ch == 8) {
				t.pop_back();
				star.pop_back();
				goto lable2;
			}
			if (ch == 32)
				continue;
				star=star+"*";
			cout<<"*";
		}
		else {
			break;
		}
		
		t+= ch;
		
	}
	if(acc.first_acc==NULL){
		chk=false;
		return chk;
	}
	x=0;
	while(tttt !=NULL){
		if(tttt->acc_data.Account_No==id){
			acc.acc_currunt=new Account_node;
			acc.acc_currunt=tttt;
			x=1;
		}
		tttt=tttt->next_acc;
	}
	if(x==1){
		if(acc.acc_currunt->acc_data.password==t)
		chk=true;
		else
		chk=false;
		return chk;
	}
	else 
	return false;
}
/////////////////////////Account profile/////////////////////////////////////
void Accounts::profile(){
		system("cls");
	cout<<"\n\n\t\t------------------------------------Profile------------------------------------\n\n\n";
	cout<<"\n\n\n\n\n\n\n\t\t\t\tUsername::"<<acc.acc_currunt->acc_data.Account_No;
	cout<<"\n\n\t\t\t\tPassword::"<<acc.acc_currunt->acc_data.password;
	cout<<"\n\n\t\t\t\tCurrunt Balance::"<<acc.acc_currunt->acc_data.amount;
}
/////////////////////Deposit Money/////////////////////
void Accounts::deposit(){
	float x;
	system("cls");
	cout<<"\n\n\t\t------------------------------------Deposit Money------------------------------------\n\n\n";
	lable:
		cout<<"\n\n\t\tEnter Amount you want to deposit::";
		cin>>x;
		if(x<=0){
			cout<<"\n\n\nDeposit Amount must be greater than 0 !!!!!!!!!\n";
			goto lable;
		}
		transaction_node *temp=acc.acc_currunt->acc_data.acc_trans.top;
		transaction_node *new_temp=new transaction_node;
		acc.acc_currunt->acc_data.amount+=x;
		new_temp->trans_data.new_amount=acc.acc_currunt->acc_data.amount;
		new_temp->trans_data.req_amount=x;
		new_temp->trans_data.trans_type="Deposit";
		 time_t now = time(0);
		 new_temp->trans_data.date_time=ctime(&now);
		 new_temp->next_trans=NULL;
		if(temp==NULL){
		acc.acc_currunt->acc_data.acc_trans.top=new transaction_node;
		acc.acc_currunt->acc_data.acc_trans.top=new_temp;	
		}
		else{
			new_temp->next_trans=new transaction_node;
			new_temp->next_trans=acc.acc_currunt->acc_data.acc_trans.top;
			acc.acc_currunt->acc_data.acc_trans.top=new_temp;
		}
		cout<<"\n\n\n\n\t\t\t\t\t**************************************************************************************************************************************************************************************************************************************************************";
		cout<<"\n\n\n\n\n\n\t\t\t\t\tThe new Balance of Account No.  "<<acc.acc_currunt->acc_data.Account_No<<"  is "<<acc.acc_currunt->acc_data.amount<<" After Deposting Amount  "<<new_temp->trans_data.req_amount<<" on "<<new_temp->trans_data.date_time; 
		cout<<"\n\t\t\t\t\t**************************************************************************************************************************************************************************************************************************************************************";

}
/////////////////////Withdraw Money///////////////////////////////
void Accounts::withdraw(){
		float x;
	system("cls");
	cout<<"\n\n\t\t------------------------------------Withdraw Money------------------------------------\n\n\n";
	cout<<"\n\n\n\n\nCurrunt Balance::"<<acc.acc_currunt->acc_data.amount;
	lable:
		if(acc.acc_currunt->acc_data.amount==0){
			cout<<"\n\n\n\t\t\tSorry you can't take out any amount,As your account balance is 0\n\n";
			return;
		}
		cout<<"\n\n\t\tEnter Amount you want to withdraw::";
		cin>>x;
		if(x<=0){
			cout<<"\n\n\nWithdraw Amount must be greater than 0 !!!!!!!!!\n";
			goto lable;
		}
		if(x>acc.acc_currunt->acc_data.amount){
			cout<<"\n\n\nYou cannot Withdraw Money more than "<<acc.acc_currunt->acc_data.amount<<"!!!!!!!!\n";
			goto lable;
		}
		transaction_node *temp=acc.acc_currunt->acc_data.acc_trans.top;
		transaction_node *new_temp=new transaction_node;
		acc.acc_currunt->acc_data.amount-=x;
		new_temp->trans_data.new_amount=acc.acc_currunt->acc_data.amount;
		new_temp->trans_data.req_amount=x;
		new_temp->trans_data.trans_type="Withdraw";
		 time_t now = time(0);
		 new_temp->trans_data.date_time=ctime(&now);
		 new_temp->next_trans=NULL;
		if(temp==NULL){
		acc.acc_currunt->acc_data.acc_trans.top=new transaction_node;
		acc.acc_currunt->acc_data.acc_trans.top=new_temp;	
		}
		else{
			new_temp->next_trans=new transaction_node;
			new_temp->next_trans=acc.acc_currunt->acc_data.acc_trans.top;
			acc.acc_currunt->acc_data.acc_trans.top=new_temp;
		}
		cout<<"\n\n\n\n\t\t\t\t\t**************************************************************************************************************************************************************************************************************************************************************";
		cout<<"\n\n\n\n\n\n\t\t\t\t\tThe new Balance of Account No.  "<<acc.acc_currunt->acc_data.Account_No<<"  is "<<acc.acc_currunt->acc_data.amount<<" After taking out Amount  "<<new_temp->trans_data.req_amount<<" on "<<new_temp->trans_data.date_time; 
		cout<<"\n\t\t\t\t\t**************************************************************************************************************************************************************************************************************************************************************";

}
///////////Transactions History///////////
void Accounts::transaction_history(){
	system("cls");
	transaction_node *temp=acc.acc_currunt->acc_data.acc_trans.top;
cout<<"\n\n\t\t------------------------------------Transactions History------------------------------------\n\n\n";
if(temp==NULL){
	cout<<"\n\n\n\nTransactions History is Empty!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
}
else{
	while(temp!=NULL){
		cout<<"\n\n\t\t\t\tDate_Time::"<<temp->trans_data.date_time;
		cout<<"\n\t\t\t\t*Money::"<<temp->trans_data.req_amount;
		cout<<"\n\t\t\t\tAction::"<<temp->trans_data.trans_type;
		cout<<"\n\t\t\t\tNew Balance::"<<temp->trans_data.new_amount;
		cout<<"\n\n\t\t\t---------------------------------------------------------";
		temp=temp->next_trans;
	}
}
}
/////////////////////Account Reset Password//////////////////////////////////
void Accounts::reset_pass(){
		string t,star;
	lable2:
		system("cls");
		cout<<"\n\n\t\t------------------------------------Reset Password------------------------------------\n\n\n";
cout<<"\n\n\n\n\n\t\t\tAccount No.::"<<acc.acc_currunt->acc_data.Account_No;
cout<<"\n\n\n\n\n\t\t\tPassword( OLD )::"<<acc.acc_currunt->acc_data.password;
	cout << "\n\n\t\t\tPassword(space will be neglected automatically)::";
	cout<<star;
	ch = '1';
	while (1) {
		ch = getch();
		if (ch != 13) {
			if (ch == 8) {
				t.pop_back();
				star.pop_back();
				goto lable2;
			}
			if (ch == 32)
				continue;
				star=star+"*";
			cout<<"*";
		}
		else {
			break;
		}
		
		t+= ch;
		
	}
	acc.acc_currunt->acc_data.password=t;
	cout<<"\n\n\n\n\nPassword Updated Successfully.................";
	cout<<"\n\n\n\n\n\t\t\tPassword( New )::"<<	acc.acc_currunt->acc_data.password;

}
///////////Employee PD////////////////////
struct PD{
		string name;
		long long int username;
		string password;
		int age;
		string city;
		string phone;
		string cnic;
		string email;
		long long int salary; 
};
////////////////////Employee PD node///////////////////////////
struct PD_node{
	PD data;
	PD_node *next;
};
///////////////////////Employee////////////////////
class Employee{  
	private:
	PD_node *first;
	PD_node *last;
	int length;
	PD_node *currunt;
	friend class  Manager;
	public:
		Employee():first(NULL),last(NULL),length(0),currunt(NULL){}
	bool login_emp();
	void emp_profile();
	void Add_account();
	void list_account();
	void search_account();
	void remove_account();
	void update_account();
	void reset_pass();
};
Employee emp;
	//--------------------Login_Employee-----------------------------//
	bool Employee:: login_emp(){
			int temp;
			PD_node *tttt=new PD_node;
			tttt=emp.first;
			long long int id;
			bool chk;
			string t,star;				
			lable:
	temp = 0;
	t= "";
				system("cls");
	cout << "\n\n\n\n\n";
	cout <<"\t\t\t\t\t\t\t" << setw(30) << "Log in"<<setw(40);
	cout << "\n\t\t\t\t\t\t\t" << setw(70);
	cout << "\n\t\t\t\t\t\t\t" << setw(88);
	cout << "\n\n\n\t\t\t\t\t\t\tUsername::";
	cin>>id;
	lable2:
				system("cls");
	cout << "\n\n\n\n\n";
	cout <<"\t\t\t\t\t\t\t" << setw(30) << "Log in"<<setw(40);
	cout << "\n\t\t\t\t\t\t\t" << setw(70);
	cout << "\n\t\t\t\t\t\t\t" << setw(88);
	cout << "\n\n\n\t\t\t\t\t\t\tUsername::"<<id;
	cout << "\n\n\n\t\t\t\t\t\t\tPassword(space will be neglected automatically)::";
	cout<<star;
	ch = '1';
	while (1) {
		ch = getch();
		if (ch != 13) {
			if (ch == 8) {
				t.pop_back();
				star.pop_back();
				goto lable2;
			}
			if (ch == 32)
				continue;
				star=star+"*";
			cout<<"*";
		}
		else {
			break;
		}
		
		t+= ch;
		
	}
	if(emp.first==NULL){
		chk=false;
		return chk;
	}
	x=0;
	while(tttt !=NULL){
		if(tttt->data.username==id){
			emp.currunt=new PD_node;
			emp.currunt=tttt;
			x=1;
		}
		tttt=tttt->next;
	}
	if(x==1){
		if(emp.currunt->data.password==t)
		chk=true;
		else
		chk=false;
		return chk;
	}
	else 
	return false;
	}
//////////////////////////Emp Profile///////////////////////
void Employee:: emp_profile(){
	system("cls");
			cout<<"\n\n\t\t------------------------------------Profile------------------------------------\n\n\n";
	cout<<"\n\n\n\n\n\n\n\t\t\t\tUsername::"<<emp.currunt->data.username;
	cout<<"\n\n\t\t\t\tPassword::"<<emp.currunt->data.password;

}
//////////////////////////////////Add Account////////////////////////////////////
void Employee:: Add_account(){
	Account_node *t=new Account_node;
	string temp;
	int x;
	long long int y;
	float am;
	if(acc.first_acc==NULL)
	y=2001;
	else 
	y=acc.last_acc->acc_data.Account_No+1;
	system("cls");
		cout<<"\n\n\t\t------------------------------------Add Account------------------------------------\n\n\n";
cout<<"\n\n\t\t\tUsername/Account No.::"<<y;
t->acc_data.Account_No=y;
cout<<"\n\n\t\t\tName::";
cin.ignore();
getline(cin,temp);
t->acc_data.name=temp;

cout<<"\n\n\t\t\tCity::";
getline(cin,temp);
t->acc_data.city=temp;
cout<<"\n\n\t\t\tAge::";
cin>>x;
t->acc_data.age=x;
cout<<"\n\n\t\t\tCNIC#::";
cin>>temp;
t->acc_data.cnic=temp;
cout<<"\n\n\t\t\tEmail::";
cin>>temp;
t->acc_data.email=temp;
cout<<"\n\n\t\t\tPhone#::";
cin>>temp;
t->acc_data.phone=temp;
lable:
cout<<"\n\n\t\t\tIntial Amount(...>=5000)::";
cin>>y;
if(y<5000)
goto lable;
t->acc_data.amount=y;
cout<<"\n\n\t\tDefault Password is your Mobile#\n\n";
cout<<"\n\n\t\t\tPassword::";
temp=t->acc_data.phone;
cout<<temp;
t->acc_data.password=temp;
t->next_acc=NULL;
if(acc.first_acc==NULL){
	acc.first_acc=acc.last_acc=t;
	acc.last_acc->next_acc=NULL;
}
else{
	acc.last_acc->next_acc=t;
	acc.last_acc=t;
	acc.last_acc->next_acc=NULL;
}
acc.acc_length+=1;
}
////////////////////////Search Account/////////////////////////
void Employee::search_account(){
		Account_node *temp=new Account_node;
	temp=acc.first_acc;
	system("cls");
		cout<<"\n\n\t\t------------------------------------Search an Account------------------------------------\n\n\n";
cout<<"\nEnter Account No.::";
cin>>x;
if(temp==NULL){
	cout<<"\n\n\n\n\n\t\tNot Found............................\n";
	return;
}
else{
	while(temp!=NULL && temp->acc_data.Account_No !=x){
		
		temp=temp->next_acc;
	}
	if(temp!=NULL){
	cout<<"\n\n\n\nAccount No.::"<<temp->acc_data.Account_No;
	cout<<"\nAcc Pass::"<<temp->acc_data.password;
	cout<<"\nAcc CNIC::"<<temp->acc_data.cnic;
	cout<<"\nAcc Name::"<<temp->acc_data.name;
	cout<<"\nAcc Age.::"<<temp->acc_data.age;
	cout<<"\nAcc City::"<<temp->acc_data.city;
	cout<<"\nAcc Mail::"<<temp->acc_data.email;
	cout<<"\nAcc MOB#::"<<temp->acc_data.phone;
	cout<<"\nAcc Blalance::"<<temp->acc_data.amount;
	}
	else
	cout<<"\n\n\n\n\n\t\tNot Found...............................";
}
}
////////////////////////Delete an Account//////////////////////
void Employee::remove_account(){
		Account_node *temp=new Account_node;
	Account_node *temp1=acc.first_acc;
	temp=acc.first_acc;
	system("cls");
		cout<<"\n\n\t\t------------------------------------Delete an Account------------------------------------\n\n\n";
cout<<"\nEnter Account No.::";
cin>>x;
if(temp==NULL){
	cout<<"\n\n\n\n\n\t\tNot Found............................\n";
	return;
}
else{
	while(temp!=NULL && temp->acc_data.Account_No !=x){
		temp1=temp;
		temp=temp->next_acc;
	}
	if(temp!=NULL){
	cout<<"\n\n\n\nAccount No.::"<<temp->acc_data.Account_No;
	cout<<"\nAcc Pass::"<<temp->acc_data.password;
	cout<<"\nAcc CNIC::"<<temp->acc_data.cnic;
	cout<<"\nAcc Name::"<<temp->acc_data.name;
	cout<<"\nAcc Age.::"<<temp->acc_data.age;
	cout<<"\nAcc City::"<<temp->acc_data.city;
	cout<<"\nAcc Mail::"<<temp->acc_data.email;
	cout<<"\nAcc MOB#::"<<temp->acc_data.phone;
	cout<<"\nAcc Blalance::"<<temp->acc_data.amount;
	cout<<"\n\n\nPress Y/y For confirm to Deletion.......";
	ch=getch();
	if(ch=='Y'||ch=='y'){
		if(acc.acc_length==1){
			delete temp;
			acc.first_acc=NULL;
			acc.acc_length=0;
		}
			else if(temp==acc.first_acc){
		temp=acc.first_acc;
		acc.first_acc=temp->next_acc;
		delete temp;
		acc.acc_length-=1;
		}
		else{
			temp1->next_acc=temp->next_acc;
			delete temp;
			acc.acc_length-=1;
		}
		cout<<"\n\n\n\nDeleted.................";
	}
	else 
	return;
	}
	else
	cout<<"\n\n\n\n\n\t\tNot Found...............................";
}
}
////////////////////////Update Account/////////////////////////
void Employee::update_account(){
		Account_node *temp=new Account_node;
	temp=acc.first_acc;
	system("cls");
		cout<<"\n\n\t\t------------------------------------Update an Account Details------------------------------------\n\n\n";
cout<<"\nEnter Account No.::";
cin>>x;
if(temp==NULL){
	cout<<"\n\n\n\n\n\t\tNot Found............................\n";
	return;
}
else{
	while(temp!=NULL && temp->acc_data.Account_No !=x){
		
		temp=temp->next_acc;
	}
	if(temp!=NULL){
	cout<<"\n\n\n\nAccount No.::"<<temp->acc_data.Account_No;
	cout<<"\nAcc Pass::"<<temp->acc_data.password;
	cout<<"\nAcc CNIC::"<<temp->acc_data.cnic;
	cout<<"\nAcc Name::"<<temp->acc_data.name;
	cout<<"\nAcc Age.::"<<temp->acc_data.age;
	cout<<"\nAcc City::"<<temp->acc_data.city;
	cout<<"\nAcc Mail::"<<temp->acc_data.email;
	cout<<"\nAcc MOB#::"<<temp->acc_data.phone;
	cout<<"\nAcc Blalance::"<<temp->acc_data.amount;
	cout<<"\n\n\n\nPress Y/y to Continue";
	ch=getch();
	if(ch=='Y'||ch=='y'){
		system("cls");
				cout<<"\n\n\t\t------------------------------------Update an Account Details------------------------------------\n\n\n";
cout<<"\n\n\t\t\tAccount No.::"<<temp->acc_data.Account_No;
cout<<"\n\n\t\t\tName::";
cin.ignore();
getline(cin,temp->acc_data.name);
cout<<"\n\n\t\t\tCity::";
getline(cin,temp->acc_data.city);
cout<<"\n\n\t\t\tAge::";
cin>>temp->acc_data.age;
cout<<"\n\n\t\t\tCNIC#::";
cin>>temp->acc_data.cnic;
cout<<"\n\n\t\t\tEmail::";
cin>>temp->acc_data.email;
cout<<"\n\n\t\t\tPhone#::";
cin>>temp->acc_data.phone;
cout<<"\n\n\t\t\tBalanace::"<<temp->acc_data.amount;
cout<<"\n\n\t\tDefault Password is your Mobile#\n\n";
cout<<"\n\n\t\t\tPassword::";
temp->acc_data.password=temp->acc_data.phone;
cout<<temp->acc_data.password;
cout<<"\n\n\nUpdated..................................";
				
	}
	}
	else
	cout<<"\n\n\n\n\n\t\tNot Found...............................";
}
	
}
////////////////////////Accounts List//////////////////////////
void Employee::list_account(){
		x=0;
	system("cls");
	cout<<"\n\n\t\t------------------------------------Accounts List------------------------------------\n\n\n";
	Account_node *temp=acc.first_acc;
	if(emp.first!=NULL){
	while(temp!=NULL){
		x++;
		cout<<"\n"<<x<<".)";
	cout<<"\nAccount No.::"<<temp->acc_data.Account_No;
	cout<<"\nAcc Name::"<<temp->acc_data.name;
	cout<<"\nAcc City::"<<temp->acc_data.city;
	cout<<"\nAcc Mail::"<<temp->acc_data.email;
	cout<<"\nAcc MOB#::"<<temp->acc_data.phone;
	cout<<"\nCurrunt Amount::"<<temp->acc_data.amount;
	cout<<"\n----------------------------------------------------\n";
	temp=temp->next_acc;
}
}
else
cout<<"\n\n\n\t\t\tEmpty................\n";
}
////////////////////////Employee Reset Password/////////////
void Employee::reset_pass(){
		string t,star;
	lable2:
		system("cls");
		cout<<"\n\n\t\t------------------------------------Reset Password------------------------------------\n\n\n";
cout<<"\n\n\n\n\n\t\t\tUsername::"<<emp.currunt->data.username;
cout<<"\n\n\n\n\n\t\t\tPassword( OLD )::"<<emp.currunt->data.password;
	cout << "\n\n\t\t\tPassword(space will be neglected automatically)::";
	cout<<star;
	ch = '1';
	while (1) {
		ch = getch();
		if (ch != 13) {
			if (ch == 8) {
				t.pop_back();
				star.pop_back();
				goto lable2;
			}
			if (ch == 32)
				continue;
				star=star+"*";
			cout<<"*";
		}
		else {
			break;
		}
		
		t+= ch;
		
	}
	emp.currunt->data.password=t;
	cout<<"\n\n\n\n\nPassword Updated Successfully.................";
	cout<<"\n\n\n\n\n\t\t\tPassword( New )::"<<emp.currunt->data.password;
}
////////////////////////Manager/////////////////////////////
class Manager{ 
	private:
	string	username;
	string password;
	public:
		Manager():username("Manager"),password("manager123"){};
	bool login_manager();
	void mang_profile();
	void add_emp();
	void show_emplist();
	void Search_emp();
	void Search_emp(string name);
	void Remove_emp();
	void Update_emp();
	void mang_pass();
};
Manager m;

	//--------------------Login_Manager-----------------------------//
	bool Manager:: login_manager(){
			int temp;
			bool chk;
			string t,star;
			lable:
	temp = 0;
	t= "";
	lable2:
				system("cls");
	cout << "\n\n\n\n\n";
	cout <<"\t\t\t\t\t\t\t" << setw(30) << "Log in"<<setw(40);
	cout << "\n\t\t\t\t\t\t\t" << setw(70);
	cout << "\n\t\t\t\t\t\t\t" << setw(88);
	cout << "\n\n\n\t\t\t\t\t\t\tUsername::Manager\n";

	cout << "\n\n\t\t\t\t\t\t\tPassword(space will be neglected automatically)::";
	cout<<star;
	ch = '1';
	while (1) {
		ch = getch();
		if (ch != 13) {
			if (ch == 8) {
				t.pop_back();
				star.pop_back();
				goto lable2;
			}
			if (ch == 32)
				continue;
				star=star+"*";
			cout<<"*";
		}
		else {
			break;
		}
		
		t+= ch;
		
	}
		if(m.password==t)
		chk=true;
		else
		chk=false;
		return chk;
		
	}
//////////////////////////Manager Profile///////////////////////
void Manager:: mang_profile(){
	system("cls");
	cout<<"\n\n\t\t------------------------------------Profile------------------------------------\n\n\n";
	cout<<"\n\n\n\n\n\n\n\t\t\t\tUsername::"<<this->username;
	cout<<"\n\n\t\t\t\tPassword::"<<this->password;

}
//////////////Add Employee////////////////////////////
void  Manager::add_emp(){
	PD_node *t=new PD_node;
	string temp;
	int x;
	long long int y;
	if(emp.first==NULL)
	y=1001;
	else 
	y=emp.last->data.username+1;
	system("cls");
		cout<<"\n\n\t\t------------------------------------Add Employee------------------------------------\n\n\n";
cout<<"\n\n\t\t\tUsername::"<<y;
t->data.username=y;
cout<<"\n\n\t\t\tName::";
cin.ignore();
getline(cin,temp);
t->data.name=temp;
cout<<"\n\n\t\t\tCity::";
getline(cin,temp);
t->data.city=temp;
cout<<"\n\n\t\t\tAge::";
cin>>x;
t->data.age=x;
cout<<"\n\n\t\t\tCNIC#::";
cin>>temp;
t->data.cnic=temp;
cout<<"\n\n\t\t\tEmail::";
cin>>temp;
t->data.email=temp;
cout<<"\n\n\t\t\tPhone#::";
cin>>temp;
t->data.phone=temp;
cout<<"\n\n\t\t\tSalary::";
cin>>y;
t->data.salary=y;
cout<<"\n\n\t\tDefault Password is your Mobile#\n\n";
cout<<"\n\n\t\t\tPassword::";
temp=t->data.phone;
cout<<temp;
t->data.password=temp;
t->next=NULL;
if(emp.first==NULL){
	emp.first=emp.last=t;
	emp.last->next=NULL;
}
else{
	emp.last->next=t;
	emp.last=t;
	emp.last->next=NULL;
}
emp.length+=1;
}
////////////Employee List/////////////////////////////////
void Manager:: show_emplist(){
	x=0;
	system("cls");
	cout<<"\n\n\t\t------------------------------------Employees List------------------------------------\n\n\n";
	PD_node *temp=emp.first;
	if(emp.first!=NULL){
	while(temp!=NULL){
		x++;
		cout<<"\n"<<x<<".)";
	cout<<"\nEmp Code::"<<temp->data.username;
	cout<<"\nEmp Name::"<<temp->data.name;
	cout<<"\nEmp City::"<<temp->data.city;
	cout<<"\nEmp Mail::"<<temp->data.email;
	cout<<"\nEmp MOB#::"<<temp->data.phone;
	cout<<"\n----------------------------------------------------\n";
	temp=temp->next;
}
}
else
cout<<"\n\n\n\t\t\tEmpty................\n";
}
/////////////////////////Search An Employee By Emp Code///////////////////////////////////
void Manager::Search_emp(){
	PD_node *temp=new PD_node;
	temp=emp.first;
	system("cls");
		cout<<"\n\n\t\t------------------------------------Search an Employee------------------------------------\n\n\n";
cout<<"\nEnter Employee Code::";
cin>>x;
if(temp==NULL){
	cout<<"\n\n\n\n\n\t\tNot Found............................\n";
	return;
}
else{
	while(temp!=NULL && temp->data.username !=x){
		
		temp=temp->next;
	}
	if(temp!=NULL){
	cout<<"\n\n\n\nEmp Code::"<<temp->data.username;
	cout<<"\nEmp Pass::"<<temp->data.password;
	cout<<"\nEmp CNIC::"<<temp->data.cnic;
	cout<<"\nEmp Name::"<<temp->data.name;
	cout<<"\nEmp Age.::"<<temp->data.age;
	cout<<"\nEmp City::"<<temp->data.city;
	cout<<"\nEmp Mail::"<<temp->data.email;
	cout<<"\nEmp MOB#::"<<temp->data.phone;
	cout<<"\nEmp Inc.::"<<temp->data.salary;
	}
	else
	cout<<"\n\n\n\n\n\t\tNot Found...............................";
}
}
/////////////////////////Search An Employee By Emp Name///////////////////////////////////
void Manager::Search_emp(string name){
	PD_node *temp=emp.first;
	x=0;
	system("cls");
		cout<<"\n\n\t\t------------------------------------Search an Employee------------------------------------\n\n\n";
cout<<"\n\n\nEmployee ::"<<name;
if(temp==NULL){
	cout<<"\n\n\n\n\n\t\tNot Found............................\n";
	return;
}
else{
	while(temp!=NULL ){
	
	if(temp->data.name==name){
	cout<<"\n\n\n\nEmp Code::"<<temp->data.username;
	cout<<"\nEmp Pass::"<<temp->data.password;
	cout<<"\nEmp CNIC::"<<temp->data.cnic;
	cout<<"\nEmp Name::"<<temp->data.name;
	cout<<"\nEmp Age.::"<<temp->data.age;
	cout<<"\nEmp City::"<<temp->data.city;
	cout<<"\nEmp Mail::"<<temp->data.email;
	cout<<"\nEmp MOB#::"<<temp->data.phone;
	cout<<"\nEmp Inc.::"<<temp->data.salary;
	cout<<"\n\n--------------------------------------------------------------";
	x=1;
}
	temp=temp->next;
}
	}
		if(x==0)
		cout<<"\n\n\n\n\n\t\tNot Found......................................";
}
/////////////////////////Remove An Employee ///////////////////////////////////
void Manager::Remove_emp(){
	int y=0;
	PD_node *temp=new PD_node;
	PD_node *temp1=emp.first;
	temp=emp.first;
	system("cls");
		cout<<"\n\n\t\t------------------------------------Remove an Employee------------------------------------\n\n\n";
cout<<"\nEnter Employee Code::";
cin>>x;
if(temp==NULL){
	cout<<"\n\n\n\n\n\t\tNot Found............................\n";
	return;
}
else{
	while(temp!=NULL && temp->data.username !=x){
		temp1=temp;
		temp=temp->next;
	}
	if(temp!=NULL){
	cout<<"\n\n\n\nEmp Code::"<<temp->data.username;
	cout<<"\nEmp Pass::"<<temp->data.password;
	cout<<"\nEmp CNIC::"<<temp->data.cnic;
	cout<<"\nEmp Name::"<<temp->data.name;
	cout<<"\nEmp Age.::"<<temp->data.age;
	cout<<"\nEmp City::"<<temp->data.city;
	cout<<"\nEmp Mail::"<<temp->data.email;
	cout<<"\nEmp MOB#::"<<temp->data.phone;
	cout<<"\nEmp Inc.::"<<temp->data.salary;
	cout<<"\n\n\nPress Y/y For confirm to Deletion.......";
	ch=getch();
	if(ch=='Y'||ch=='y'){
		if(emp.length==1){
			delete temp;
			emp.first=NULL;
			emp.length=0;
		}
		else if(emp.first->data.username==x){
		temp=emp.first;
		emp.first=temp->next;
		delete temp;
			emp.length-=1;
		}
		else{
			temp1->next=temp->next;
			delete temp;
			emp.length-=1;
		}
		cout<<"\n\n\n\nDeleted.................";
	}
	else 
	return;
	}
	else
	cout<<"\n\n\n\n\n\t\tNot Found...............................";
}
}
/////////////////////////Update an Employee Details///////////////////////////////////
void Manager::Update_emp(){
	PD_node *temp=new PD_node;
	temp=emp.first;
	system("cls");
		cout<<"\n\n\t\t------------------------------------Update an Employee Details------------------------------------\n\n\n";
cout<<"\nEnter Employee Code::";
cin>>x;
if(temp==NULL){
	cout<<"\n\n\n\n\n\t\tNot Found............................\n";
	return;
}
else{
	while(temp!=NULL && temp->data.username !=x){
		
		temp=temp->next;
	}
	if(temp!=NULL){
	cout<<"\n\n\n\nEmp Code::"<<temp->data.username;
	cout<<"\nEmp Pass::"<<temp->data.password;
	cout<<"\nEmp CNIC::"<<temp->data.cnic;
	cout<<"\nEmp Name::"<<temp->data.name;
	cout<<"\nEmp Age.::"<<temp->data.age;
	cout<<"\nEmp City::"<<temp->data.city;
	cout<<"\nEmp Mail::"<<temp->data.email;
	cout<<"\nEmp MOB#::"<<temp->data.phone;
	cout<<"\nEmp Inc.::"<<temp->data.salary;
	cout<<"\n\n\n\nPress Y/y to Continue";
	ch=getch();
	if(ch=='Y'||ch=='y'){
		system("cls");
				cout<<"\n\n\t\t------------------------------------Update an Employee Details------------------------------------\n\n\n";
cout<<"\n\n\t\t\tUsername::"<<temp->data.username;
cout<<"\n\n\t\t\tName::";
cin.ignore();
getline(cin,temp->data.name);
cout<<"\n\n\t\t\tCity::";
getline(cin,temp->data.city);
cout<<"\n\n\t\t\tAge::";
cin>>temp->data.age;
cout<<"\n\n\t\t\tCNIC#::";
cin>>temp->data.cnic;
cout<<"\n\n\t\t\tEmail::";
cin>>temp->data.email;
cout<<"\n\n\t\t\tPhone#::";
cin>>temp->data.phone;
cout<<"\n\n\t\t\tSalary::";
cin>>temp->data.salary;
cout<<"\n\n\t\tDefault Password is your Mobile#\n\n";
cout<<"\n\n\t\t\tPassword::";
temp->data.password=temp->data.phone;
cout<<temp->data.password;
cout<<"\n\n\nUpdated..................................";
				
	}
	}
	else
	cout<<"\n\n\n\n\n\t\tNot Found...............................";
}
}
//////////////////////////////////////Manager Password Change/////////////////////////////////
void Manager:: mang_pass(){
	string t,star;
	lable2:
		system("cls");
		cout<<"\n\n\t\t------------------------------------Reset Password------------------------------------\n\n\n";
cout<<"\n\n\n\n\n\t\t\tUsername::"<<this->username;
cout<<"\n\n\n\n\n\t\t\tPassword( OLD )::"<<this->password;
	cout << "\n\n\t\t\tPassword(space will be neglected automatically)::";
	cout<<star;
	ch = '1';
	while (1) {
		ch = getch();
		if (ch != 13) {
			if (ch == 8) {
				t.pop_back();
				star.pop_back();
				goto lable2;
			}
			if (ch == 32)
				continue;
				star=star+"*";
			cout<<"*";
		}
		else {
			break;
		}
		
		t+= ch;
		
	}
	this->password=t;
	cout<<"\n\n\n\n\nPassword Updated Successfully.................";
	cout<<"\n\n\n\n\n\t\t\tPassword( New )::"<<this->password;


}

int page(){
	lable:
	system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
	cout << setw(50) << setfill('*') << "XYZ Bank Of PK" << setw(50) << setfill('*');
	cout << "\n\t\t\t\t"<<setw(50) << setfill('*') << "                         " << setw(50) << setfill('*');
	cout << "\n\t\t\t\t"<< setw(101) << setfill('*');
	cout << "\n\t\t\t\t*";tab1();cout << "\t\t       *";
	cout << "\n\t\t\t\t*\t1.>Manager";tab1();cout << "*";
	cout << "\n\t\t\t\t*";tab1();cout << "\t\t       *";
	cout << "\n\t\t\t\t*\t2.>Employee  ";tab1();cout << "*";
	cout << "\n\t\t\t\t*";tab1();cout << "\t\t       *";
	cout << "\n\t\t\t\t*\t3.>Account  ";tab1();cout << "*";
	cout << "\n\t\t\t\t" << setw(100) << setfill('*');
	cout << "\n\t\t\t\t" << setw(120) << setfill('*');
	cout<<"\n\n\n\n\n\t\t\t\tEnter your Selection::";
	cin>>x;
	return x;
}

void page_1(){
	string st;
	lable:
	system("cls");
		cout<<"\n\n\n\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	        cout<<"\n\t\t\t|                                Manager                                                       |\n";
	          cout<<"\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n\n";
		cout << "\n\t\t\t\t\t1).Profile";
		cout << "\n\n\t\t\t\t\t2).Add Employee";
		cout << "\n\n\t\t\t\t\t3).Employees List";	
		cout << "\n\n\t\t\t\t\t4).Search Employee (By Emp Code)";
		cout << "\n\n\t\t\t\t\t5).Search Employee (By Emp Name)";	
		cout << "\n\n\t\t\t\t\t6).Remove an Employee ";	
		cout << "\n\n\t\t\t\t\t7).Update an Employee Details ";	
		cout << "\n\n\t\t\t\t\t8).Bank Accounts List";	
		cout << "\n\n\n\n\n\n\t\t\t\t\t9).Reset Password";	
		cout << "\n\n\t\t\t\t\t0).Log Out";	


		cout<<"\n\n\n\t\t\t\t\tEnter Your Selection::";
		cin>>x;
		
switch(x){
	case 1:
		m.mang_profile();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;
	case 2:
	m.add_emp();
	cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
	getch();
	goto lable;
	case 3:
	m.show_emplist();
	cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
	getch();
	goto lable;
	case 4:
	m.Search_emp();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
	getch();
	goto lable;
		case 5:
			system("cls");
	cout<<"\n\n\t\t------------------------------------Search an Employee------------------------------------\n\n\n";
    cout<<"\n\n\nEmployee Name ::";
    cin.ignore();
	getline(cin,st);
	m.Search_emp(st);
	cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
	getch();
	goto lable;
	case 6:
			m.Remove_emp();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
	getch();
	goto lable;
	case 7:
			m.Update_emp();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
	getch();
	goto lable;
	case 8:
		emp.list_account();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
	getch();
	goto lable;
	case 9:
			m.mang_pass();
	cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
	getch();
	goto lable;
	case 0:
		system("cls");
		cout<<"\n\n\t\t------------------------------------LOG OUT------------------------------------\n\n\n";
		cout<<"\n\n\n\t\t\tPress Enter To Log Out...................";
		ch=getch();
		if(ch==13)
		return;
		else
		goto lable;
	default:
		cout<<"\n\n\n\ninvalid Selection...................";
			cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
	getch();
	goto lable;
}
}
void page_2(){
	lable:
	system("cls");
	cout<<"\n\n\n\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	    cout<<"\n\t\t\t|                                Employee                                                       |\n";
	      cout<<"\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n\n";
		cout << "\n\t\t\t\t\t1).Profile";
		cout << "\n\n\t\t\t\t\t2).Add Account";
		cout << "\n\n\t\t\t\t\t3).Search Account (By  Account# )";
		cout << "\n\n\t\t\t\t\t4).Remove an Account";	
		cout << "\n\n\t\t\t\t\t5).Update an Account Details ";	
		cout << "\n\n\t\t\t\t\t6).Bank Accounts List";	
		cout << "\n\n\n\n\n\n\t\t\t\t\t7).Reset Password";	
		cout << "\n\n\t\t\t\t\t0).Log Out";	


		cout<<"\n\n\n\t\t\t\t\tEnter Your Selection::";
		cin>>x;
		switch(x){
				case 1:
		emp.emp_profile();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;
				case 2:
		emp.Add_account();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;
		        case 3:
		emp.search_account();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;  	
		       case 4:
		emp.remove_account();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;
		       case 5:
		emp.update_account();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;
		       	case 6:
		emp.list_account();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;
		        case 7:
		emp.reset_pass();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;
	    	   case 0:
		system("cls");
		cout<<"\n\n\t\t------------------------------------LOG OUT------------------------------------\n\n\n";
		cout<<"\n\n\n\t\t\tPress Enter To Log Out...................";
		ch=getch();
		if(ch==13)
		return;
		else
		goto lable;
        	default:
		cout<<"\n\n\n\ninvalid Selection...................";
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
	    getch();
	    goto lable;
		}
}
void page_3(){
	lable:
	system("cls");
		cout<<"\n\n\n\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	    cout<<"\n\t\t\t|                                Account                                                      |\n";
	      cout<<"\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n\n";
		cout << "\n\t\t\t\t\t1).Profile";
		cout << "\n\n\t\t\t\t\t2).Deposit Money";
		cout << "\n\n\t\t\t\t\t3).Widthdraw Money";	
		cout<<  "\n\n\t\t\t\t\t4).Transaction History";
		cout << "\n\n\n\n\n\n\t\t\t\t\t5).Reset Password";	
		cout << "\n\n\t\t\t\t\t0).Log Out";	


		cout<<"\n\n\n\t\t\t\t\tEnter Your Selection::";
		cin>>x;
		switch(x){
				case 1:
		acc.profile();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;
				case 2:
		acc.deposit();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;
		        case 3:
		acc.withdraw();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;  
		       case 4:
		acc.transaction_history();	
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;  
		       case 5:
		acc.reset_pass();
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
		getch();
		goto lable;
	    	   case 0:
		system("cls");
		cout<<"\n\n\t\t------------------------------------LOG OUT------------------------------------\n\n\n";
		cout<<"\n\n\n\t\t\tPress Enter To Log Out...................";
		ch=getch();
		if(ch==13)
		return;
		else
		goto lable;
        	default:
		cout<<"\n\n\n\ninvalid Selection...................";
		cout<<"\n\n\n\n\n\n\t\t\tPress Any Key To Go Back...............";
	    getch();
	    goto lable;
		}
}
int main(){
	int i;
	system("color 47");
	while(1){
		x=page();
		switch(x){
		case 1:
			system("cls");
		for(i=0;i<3;i++){
			if(m.login_manager()){
				break;
			}
		}
		if(i>=3){
			cout<<"\n\n\t\t\t\tToo much Try, but Fail\n\n\t\t\t\tPress any key to go back.........";
			getch();
			break;
		}
		else{
			page_1();
	    }	
	    break;
	    case 2:
	    		system("cls");
		for(i=0;i<3;i++){
			if(emp.login_emp()){
				break;
			}
		}
		if(i>=3){
			cout<<"\n\n\t\t\t\tToo much Try, but Fail\n\n\t\t\t\tPress any key to go back.........";
			getch();
			break;
		}
		else{
			page_2();
	    }
	    break;
		case 3:	
		  		system("cls");
		for(i=0;i<3;i++){
			if(acc.Account_Login()){
				break;
			}
		}
		if(i>=3){
			cout<<"\n\n\t\t\t\tToo much Try, but Fail\n\n\t\t\t\tPress any key to go back.........";
			getch();
			break;
		}
		else{
			page_3();
	    }
		break;
	}}
	return 0;
}
