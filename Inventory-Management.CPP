#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    const int max_item = 100 ;
    string item_name[max_item] ;
    int quantity[max_item] ;
    int price[max_item] ;
    string search_item ;
    int counter = 0 ;
    string item_remove ;
    string item_update ;
    int update_quantity ;

cout<<"=== Inventory Management System ===" << endl << endl ;
        cout<<"1. Add Item " << endl ;
        cout<<"2. Remove Item " << endl ;
        cout<<"3. Update Quantity " << endl ;
        cout<<"4. Search Item " << endl ;
        cout<<"5. Display items " << endl ;
        cout<<"6. Exit " << endl << endl ;

    while(true)
    {


        cout<<"Choose an option: " ;
        int option ;
        cin >> option ;
        cout<< endl ;


        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a NUMBER." << endl << endl ;
            continue;
        }

        if ( option < 1 || option > 6  )
        {
            cout<< "Invalid input!" << endl << endl ;
        }
        else if (option == 6)
        {
            cout<< "Goodbye!" << endl ;
            break ;
        }
        else if ( option == 1 )
        {
            if ( counter < max_item )
            {
                cout<<"Enter item name: " ;
                cin >> item_name[counter] ;
                cout<< endl ;

                cout<< "Enter quantity: " ;
                cin>> quantity[counter] ;
                cout<< endl ;

                cout<< "Enter unit price: " ;
                cin >> price[counter] ;
                cout << endl ;

                cout<< "Item \""<<  item_name[counter] << "\" added." << endl << endl ;
                counter++ ;
            }
            else
                cout<<"Inventory is full!" << endl << endl ;
        }
        else if (option == 2)
        {
            cout<< "Enter item to remove: " ;
            cin >> item_remove ;
            bool found = false ;

            for (int i = 0 ; i < counter ; i++)
            {
                if(item_name[i] == item_remove)
                {
                    for(int j = i ; j < counter-1 ; j++ )
                    {
                        item_name[j] = item_name[j+1] ;
                        quantity[j] = quantity[j+1] ;
                        price[j] = price[j+1] ;
                    }
                    counter -- ;
                    found = true ;
                    cout <<"\"" << item_remove << "\"" << " removed successfully" << endl << endl ;
                    break ;
                }
            }
            if (!found )
                cout<<"Item not found!" << endl << endl ;
        }
        else if ( option == 3 )
        {
            cout<< "Enter item name: "  ;
            cin >> item_update ;
            cout<< endl ;

            cout<< "Enter quantity change: " ;
            cin >> update_quantity ;
            cout<< endl ;

            bool found = false ;

            for( int k = 0 ; k < counter ; k ++)
            {
                if(item_name[k] == item_update )
                {
                    quantity[k] += update_quantity ;
                    cout<< "Updated quantity: " << quantity[k] << endl << endl;
                    found = true ;
                    break ;
                }
            }
            if (!found )
                cout<<"Item not found" << endl << endl ;
        }
        else if (option == 4)
        {
            cout<<"Enter item to search: " ;
            cin >> search_item ;
            bool found = false ;
            for(int d = 0 ; d < counter ; d++)
            {
                if ( item_name[d] == search_item )
                {
                    cout<< "Item is found!" << endl ;
                    cout<< "item: " << item_name[d] << "  |  Qty: "<< quantity[d] << endl ;
                    cout<<"price: " << price[d] << endl << endl ;
                    found = true ;
                    break ;
                }
            }
            if (!found)
            {
                cout<<"Item \"" << search_item << "\"" << " not found!" << endl << endl;
            }
        }
        else if (option == 5)
        {
            if (counter == 0)
            {
                cout << "Inventory is Empty!" << endl << endl;
            }
            else
            {
                for (int i = 0; i < counter; i++)
                {
                    int total = quantity[i] * price[i];
                    cout << "Item: " << item_name[i] << " | Qty: " << quantity[i] << " | Price: " << price[i] << " EGP | Total: " << total << " EGP" << endl;
                }
                cout << endl;
            }
        }
    }
    return 0;
}