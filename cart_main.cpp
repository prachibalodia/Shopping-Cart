#include <iostream>
#include"datamodel.h"
#include<vector>
using namespace std;

vector<Product> allProducts= {
    Product(1, "apple", 26),
    Product(3, "mango", 16),
    Product(2, "guava", 36),
    Product(5, "banana", 56),
    Product(4, "strawberry", 29),
    Product(6, "pineapple", 20), 
};
Product* chooseProduct(){
    //Display the list of Products
    string productList;
    cout<<"Available Products"<<endl;

    for(auto product: allProducts){
        productList.append(product.getDisplayName());
    }

    cout<<productList<<endl;

    cout<<"-----------------"<<endl;

    //choose product
    string choice;
    cin>>choice;

    for(int i=0;i<allProducts.size();i++){
        if(allProducts[i].getShortName()==choice){
            return &allProducts[i];
        }
    }
    cout<<"Product not Found!"<<endl;
    return NULL;

}

bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }

    int total= cart.getTotal();
    cout<<"Pay in Cash\n";
    int paid;
    cin>> paid;
    if(paid>total){
        cout<<"Change: Rs."<< paid-total<<endl;
        cout<<"Thank You for Shopping!\n";
        return true;
    }
    
    else{
        cout<<"Not enough Cash!\n";
        return false;

    }
}

int main()
{
    char action;
    Cart cart;
    while(true){
        cout<<"Select Action- (a)dd item, (v)iew cart, (c)heckout"<<endl;
        cin>>action;
        if(action == 'a'){
            //Add to Cart
            //View all Products + Choose + Add to the cart
            Product * product= chooseProduct();
            if(product!= NULL){
                cout<<"Added to the Cart "<<product->getDisplayName()<<endl;
                
                cart.addProduct(*product);
            }
        }
        else if(action == 'v'){
            //View the Cart
            cout<<"-------------------------"<<endl;
            cout<<cart.viewCart();
            cout<<"-------------------------"<<endl;
        }
        else{
            //Checkout-> access info from cart, and display total amount, ask user for payment
            //return true if paid by user 
            cart.viewCart();
            if(checkout(cart)){
                break;
            }


        }
    }
 
return 0;
}