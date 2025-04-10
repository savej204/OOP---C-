#include <bits/stdc++.h>
using namespace std;

class Product {
    private:
        string product;
        string name;
        string description;
        string category;
        double unitPrice;
        int stockQuantity;
    public:
        Product() {
            string product ;
            string name ;
            string description ;
            string category ;
            double unitPrice ;
            int stockQuantity ;
        }

        ~Product() {
            string product ;
            string name ;
            string description ;
            string category ;
            double unitPrice ;
            int stockQuantity ;
        }

        Product(string sp, string ten, string mt, string dm, double price, int num) {
            this -> product = sp;
            this -> name = ten;
            this -> description = mt;
            this -> category = dm;
            this -> unitPrice = price;
            this -> stockQuantity = num;
        }

        Product(const Product& prd) {
            this -> product = prd.product;
            this -> name = prd.name;
            this -> description = prd.description;
            this -> category = prd.category;
            this -> unitPrice = prd.unitPrice;
            this -> stockQuantity = prd.stockQuantity;
        }

        void input() {
            cout << "Ma san pham: "; cin >> product;
            cout << "Ten san pham: "; cin >> name;
            cout << "Mo ta san pham: "; cin >> description;
            cout << "Danh muc san pham: "; cin >> category; 
            cout << "Don gia: "; setUnitPrice();
            cout << "So luong ton kho: "; cin >> stockQuantity;
        }

        string getProductld() {
            return product;
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return description;
        }

        string getCategory() {
            return category;
        }

        double getUnitPrice() {
            return unitPrice;
        }

        int getStockQuantity() {
            return stockQuantity;
        }

        void setProductld() {
            string product;
            this -> product = product;
        }

        void setName() {
            string name; this -> name = name;
        }

        void setDescription() {
            string description; this -> description = description;
        }

        void setCategory() {
            string category; this -> category = category;
        }

        void setUnitPrice() {
            double unitPrice; 
            cin >> unitPrice;
            this -> unitPrice = unitPrice;
            while(unitPrice < 0){
                cout << "Nhap lai: "; cin >> unitPrice;
            }
        }

        void setStockQuantity() {
            int stockQuantity; this -> stockQuantity = stockQuantity;
        }

        bool isAvailable() {
            if(stockQuantity > 0 ) return true;
            else return false;
        }
        
        void sale(int saleQuantity) {
            isAvailable();
            if(saleQuantity > stockQuantity) exit(0); //Ko du de ban
            else cout << "SUCCESS !!! \n";
            stockQuantity -= saleQuantity;
            cout << "San pham con lai trong kho: " << getStockQuantity();

        }
    
        double caculatelventoryValue() {
            double sum;
            sum = stockQuantity * unitPrice;
            return sum;
        }

        string generateSKU() {
            string sku = "";
            for(int j = 0; j < product.size(); j++) {
                product[j] = toupper(product[j]);
                sku += product[j];
            }sku += "-";
            for(int i  = 0; i < name.size(); i++) {
                name[i] = toupper(name[i]);
                sku += name[i];
            }
            return sku;
        }

        void display() {
            cout << "Ma san pham: " << getProductld() << endl;
            cout << "Ten san pham: " << getName() << endl;
            cout << "Mo ta san pham: " << getDescription() << endl;
            cout << "Danh muc san pham: " << getCategory() << endl;
            cout << "Don gia: " << getUnitPrice() << endl;
            cout << "Kiem tra trang thai kho hang: " << isAvailable() << endl;
            sale(5); cout << endl;
            cout << "Tong gia tri luong hang ton tai trong kho: " << caculatelventoryValue() << endl;
            cout << "SKU: " << generateSKU();
        }
};

int main() {
   Product hl;
   Product dt1("","","","",1,2);
   Product drp(dt1);
   hl.input(); cout << "---------------------------" << endl;
   hl.display();
}
