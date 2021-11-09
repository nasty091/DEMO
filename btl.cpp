#include <iostream>

using namespace std;

class MonHoc{
	private:
		string HocPhan,TenHocPhan;
	public:
		MonHoc();
		MonHoc(string HocPhan, string TenHocPhan);
		~MonHoc();
		void setHocPhan(string HocPhan);
		string getHocPhan();
		void setTenHocPhan(string TenHocPhan);
		string getTenHocPhan();
		friend istream& operator >> (istream& is, MonHoc& hp);
};
MonHoc::MonHoc(){
	HocPhan = "";
	TenHocPhan = "";
}
MonHoc::MonHoc(string HocPhan, string TenHocPhan){
	this->HocPhan = HocPhan;
	this->TenHocPhan = TenHocPhan;
}
MonHoc::~MonHoc(){
	
}
void MonHoc::setHocPhan(string HocPhan){
	this->HocPhan = HocPhan;
}
string MonHoc::getHocPhan(){
	return HocPhan;
}
void MonHoc::setTenHocPhan(string TenHocPhan){
	this->TenHocPhan = TenHocPhan;
}
string MonHoc::getTenHocPhan(){
	return TenHocPhan;
}
istream& operator >> (istream& is, MonHoc& hp){
	cout << "Nhap hoc phan: ";
	getline(is, hp.HocPhan);
	cout << "Nhap ten hoc phan: ";
	getline(is, hp.TenHocPhan);
	return is;
}


class Diem : public MonHoc{
	private:
		float DiemQuaTrinh,DiemThi,DiemTong;
	public:
		Diem();
		Diem(float DiemQuaTrinh, float DiemThi, float DiemTong);
		~Diem();
		void setDiemQuaTrinh(float DiemQuaTrinh);
		float getDiemQuaTrinh();
		void setDiemThi(float DiemThi);
		float getDiemThi();
		void setDiemTong(float DiemTong);
		float getDiemTong();
		friend istream& operator >> (istream& is, Diem& ds);
};
Diem::Diem(){
	DiemQuaTrinh = 0;
	DiemThi = 0;
	DiemTong = 0;
}
Diem::Diem(float DiemQuaTrinh, float DiemThi, float DiemTong){
	this->DiemQuaTrinh = DiemQuaTrinh;
	this->DiemThi = DiemThi;
	this->DiemTong = DiemTong;
}
Diem::~Diem(){
	
}
void Diem::setDiemQuaTrinh(float DiemQuaTrinh){
	this->DiemQuaTrinh = DiemQuaTrinh;
}
float Diem::getDiemQuaTrinh(){
	return DiemQuaTrinh;
}
void Diem::setDiemThi(float DiemThi){
	this->DiemThi = DiemThi;
}
float Diem::getDiemThi(){
	return DiemThi;
}
void Diem::setDiemTong(float DiemTong){
	this->DiemTong = DiemTong;
}
float Diem::getDiemTong(){
	return DiemTong;
}
istream& operator >> (istream& is, Diem& ds){
	MonHoc *a = static_cast <MonHoc *> (&ds);
	is >> *a;
	fflush(stdin);
	cout << "Nhap diem qua trinh: ";
	is >> ds.DiemQuaTrinh;
	cout << "Nhap diem thi: ";
	is >> ds.DiemThi;
	ds.DiemTong = (float)(ds.DiemQuaTrinh + ds.DiemThi) / 2;
	return is;
}

class TinChi : public Diem{
	private:
		int SoTinChi;
	public:
		TinChi();
		TinChi(int SoTinChi);
		~TinChi();
		void setSoTinChi(int SoTinChi);
		int getSoTinChi();
		friend istream& operator >> (istream& is, TinChi& tc);
		friend ostream& operator << (ostream& os, TinChi& tc);
};
TinChi::TinChi(){
	SoTinChi = 0;
}
TinChi::TinChi(int SoTinChi){
	this->SoTinChi = SoTinChi;
}
TinChi::~TinChi(){
	
}
void TinChi::setSoTinChi(int SoTinChi){
	this->SoTinChi = SoTinChi;
}
int TinChi::getSoTinChi(){
	return SoTinChi;
}
istream& operator >> (istream& is, TinChi& tc){
	Diem *a = static_cast <Diem *> (&tc);
	fflush(stdin);
	is >> *a;
	cout << "Nhap so tin chi: ";
	is >> tc.SoTinChi;
	return is;
}
ostream& operator << (ostream& os, TinChi& tc){
	if(tc.getDiemTong() < 4){
		os << tc.getHocPhan() << "\t" << tc.getTenHocPhan() << "\t" << tc.getDiemQuaTrinh() << "\t" << tc.getDiemThi()<< "\t" << tc.getDiemTong() << "\t" << tc.SoTinChi << "\t" << "CHUA DAT" << endl;
	}
	else{
		os << tc.getHocPhan() << "\t" << tc.getTenHocPhan() << "\t" << tc.getDiemQuaTrinh() << "\t" << tc.getDiemThi()<< "\t" << tc.getDiemTong() << "\t" << tc.SoTinChi << "\t" << "DAT" << endl;
	}
	return os;
}

class SinhVien : public Diem{
	private:
		string HoTen,Lop,MSSV;
	public:
		friend istream& operator >> (istream& is, SinhVien& sv);
		friend ostream& operator << (ostream& os, const SinhVien& sv);
		void XepLoai();
};
istream& operator >> (istream& is, SinhVien& sv){
	cout << "Nhap ho va ten: ";
	getline(is,sv.HoTen);
	cout << "Nhap lop: ";
	getline(is,sv.Lop);
	cout << "Nhap ma so sinh vien: ";
	getline(is,sv.MSSV);
	return is;
}
ostream& operator << (ostream& os, const SinhVien& sv){
	os << "Ten: " << sv.HoTen << endl;
	os << "Lop: " << sv.Lop << endl;
	os << "MSSV: " << sv.MSSV << endl;
	return os;
}

class Node{
	public:
		TinChi data;
		Node *pNext;
		Node(TinChi data){
			this->data = data;
			pNext = NULL;
		}
};

class SingleList{
	private:
		Node *pHead;
		Node *pTail;
		int size;
	public:
		SingleList();
		~SingleList();
		void addLast(TinChi& source);
		Node* getHead();
		Node* getTail();
		void traverse();
		void SortByDiemTong();
		void SortByDiemQuaTrinh();
		void SortByDiemThi();
		void SortByTenHocPhan();
		void Swap(TinChi& source1, TinChi& source2);
		void findMaxDiemTong();
		void findMinDiemTong();
		int SoMonDat();
		void MonDat();
		int SoMonChuaDat();
		void MonChuaDat();
		int SoTinChiTichLuy();
		void SearchByHocPhan();
		int List_Size();
		void ThemDau(TinChi& source);
		void ThemCuoi(TinChi& source);
		void ThemHocPhan(TinChi& source);
};
SingleList::SingleList(){
	pHead = NULL;
	pTail = NULL;
	size = 0;
}
SingleList::~SingleList(){
	
}
void SingleList::addLast(TinChi& source){
    Node *pNode = new Node(source);
    if(size == 0){
        pHead = pTail = pNode;
    } else {
        pTail->pNext = pNode;
        pTail = pNode;
    }
    size++;
}
void SingleList::traverse(){
	Node* temp = pHead;
	while(temp != NULL){
		cout << temp->data;
		temp = temp->pNext;
	}
}
void SingleList::SortByDiemTong(){
	for(Node* temp = pHead; temp != NULL; temp = temp->pNext){
		for(Node* temp2 = temp->pNext; temp2 != NULL; temp2 = temp2->pNext){
			if(temp->data.getDiemTong() < temp2->data.getDiemTong()){
				Swap(temp->data, temp2->data);
			}
		}
	}
	traverse();
}
void SingleList::SortByDiemQuaTrinh(){
	for(Node* temp = pHead; temp != NULL; temp = temp->pNext){
		for(Node* temp2 = temp->pNext; temp2 != NULL; temp2 = temp2->pNext){
			if(temp->data.getDiemQuaTrinh() < temp2->data.getDiemQuaTrinh()){
				Swap(temp->data, temp2->data);
			}
		}
	}
	traverse();
}
void SingleList::SortByDiemThi(){
	for(Node* temp = pHead; temp != NULL; temp = temp->pNext){
		for(Node* temp2 = temp->pNext; temp2 != NULL; temp2 = temp2->pNext){
			if(temp->data.getDiemThi() < temp2->data.getDiemThi()){
				Swap(temp->data, temp2->data);
			}
		}
	}
	traverse();
}
void SingleList::SortByTenHocPhan(){
	for(Node* temp = pHead; temp != NULL; temp = temp->pNext){
		for(Node* temp2 = temp->pNext; temp2 != NULL; temp2 = temp2->pNext){
			if(temp->data.getTenHocPhan() > temp2->data.getTenHocPhan()){
				Swap(temp->data, temp2->data);
			}
		}
	}
	traverse();
}
void SingleList::Swap(TinChi& source1, TinChi& source2){
	TinChi t = source1;
	source1 = source2;
	source2 = t;
}
void SingleList::findMaxDiemTong(){
	Node* temp = pHead;
	float max;
	string name;
	while(temp != NULL){
		if(temp->data.getDiemTong() > max){
			max = temp->data.getDiemTong();
			name = temp->data.getTenHocPhan();
		}
		temp = temp->pNext;
	}
	cout << "Hoc phan " << name <<  " co diem tong cao nhat: " << max << endl;
}

void SingleList::findMinDiemTong(){
	Node* temp = pHead;
	float min;
	string name;
	while(temp != NULL){
		if(temp->data.getDiemTong() < min){
			min = temp->data.getDiemTong();
			name = temp->data.getTenHocPhan();
		}
		temp = temp->pNext;
	}
	cout << "Hoc phan " << name <<  " co diem tong thap nhat: " << min << endl;
}
int SingleList::SoMonDat(){
	Node* temp = pHead;
	int count = 0;
	while(temp != NULL){
		if(temp->data.getDiemTong() >= 4){
			count++;
		}
		temp = temp->pNext;
	}
	return count;
}
void SingleList::MonDat(){
	Node* temp = pHead;
	string name;
	while(temp != NULL){
		if(temp->data.getDiemTong() >= 4){
			cout << temp->data.getTenHocPhan() << ": " << temp->data.getSoTinChi() << " tin chi" << endl;
		}
		temp = temp->pNext;
	}
}
int SingleList::SoMonChuaDat(){
	Node* temp = pHead;
	int count = 0;
	while(temp != NULL){
		if(temp->data.getDiemTong() < 4){
			count++;
		}
		temp = temp->pNext;
	}
	return count;
}
void SingleList::MonChuaDat(){
	Node* temp = pHead;
	string name;
	while(temp != NULL){
		if(temp->data.getDiemTong() < 4){
			cout << temp->data.getTenHocPhan() << ": " << temp->data.getSoTinChi() << " tin chi" << endl;
		}
		temp = temp->pNext;
	}
}
int SingleList::SoTinChiTichLuy(){
	Node* temp = pHead;
	int sum = 0;
	while(temp != NULL){
		if(temp->data.getDiemTong() >= 4){
			sum += temp->data.getSoTinChi();
		}
		temp = temp->pNext;
	}
	return sum;
}
void SingleList::SearchByHocPhan(){
	Node* temp = pHead;
	Node* temp2 = NULL;
	string name;
	cout << "Nhap hoc phan can tim kiem: ";
	getline(cin,name);
	while(temp != NULL){
		if(name == temp->data.getHocPhan()){
			cout << temp->data;
			temp2 = temp;
		}
		temp = temp->pNext;
	}
	if(temp2 == NULL){
		cout << "Khong tim thay hoc phan!" << endl;
	}
}
int SingleList::List_Size(){
	Node* temp = pHead;
	int size = 0;
	while(temp != NULL){
		temp = temp->pNext;
		size++;
	}
	return size;
}
void SingleList::ThemDau(TinChi& source){
	Node* pNode = new Node(source);
	if(pHead == NULL){
		pHead = pNode;
	}
	else{
		pNode->pNext = pHead;
		pHead = pNode;
	}
}
void SingleList::ThemCuoi(TinChi& source){
	Node* pNode = new Node(source);
	if(pHead == NULL){
		pHead = pNode;
	}
	else{
		Node* temp = pHead;
		while(temp != NULL){
			temp = temp->pNext;
		}
		temp->pNext = pNode;
	}
}
void SingleList::ThemHocPhan(TinChi& source){
	int vitri;
	cout << "Nhap vi tri can them: ";
	cin >> vitri;
	if(vitri < 0 || vitri >= List_Size()){
		cout << "Vi tri khong hop le!" << endl;
		return;
	}
	if(vitri == 0){
		ThemDau(source);
	}
	else if(vitri = List_Size() - 1){
		ThemCuoi(source);
	}
	else{
		Node* pNode = new Node(source);
		Node* pIns = pHead;
		Node* pPre = NULL;
		int i = 0;
		while(pIns != NULL){
			if(i == vitri){
				break;
			}
			pPre = pIns;
			pIns = pIns->pNext;
			i++;
		} 
		pNode->pNext = pIns;
		pPre->pNext = pNode;
	}
}
int main(){
	SingleList a;
	int n;
	cout << "Nhap so luong mon hoc: ";
	cin >> n;
	for(int i = 1; i <= n; i++){
		TinChi data;
		cin >> data;
		a.addLast(data);
	}
//	a.traverse();
//	cout << endl << "Sap xeo theo diem tong: " << endl;
//	a.SortByDiemTong();
//	cout << endl << "Sap xeo theo diem qua trinh: " << endl;
//	a.S	a.traverse();ortByDiemQuaTrinh();
//	cout << endl << "Sap xeo theo diem thi: " << endl;
//	a.SortByDiemThi();
//	cout << endl << "Sap xeo theo ten hoc phan: " << endl;
//	a.SortByTenHocPhan();
//	a.findMaxDiemTong();
//	a.findMinDiemTong();
//	cout << endl << "So luong mon hoc dat la  " << a.SoMonDat() << ":" << endl;
//	a.MonDat(); 
//	cout << endl << "So luong mon hoc chua dat la  " << a.SoMonChuaDat() << ":" << endl;
//	a.MonChuaDat(); 
//	cout << endl << "So tin chi tich luy duoc la: " << a.SoTinChiTichLuy() << endl;
//	fflush(stdin);
//	cout << endl;
//	a.SearchByHocPhan();
	TinChi data2;
	cout << "Nhap mon hoc can them:" << endl;
	cin >> data2;

//	cout << "Nhap vi tri can them: ";
//	cin >> vitri;
//	a.ThemCuoi(data2);
//	a.ThemDau(data2);
	a.ThemHocPhan(data2);
	a.traverse();
	return 0;
}