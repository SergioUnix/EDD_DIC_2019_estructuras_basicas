#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{

    int a, b;
    do{


        cout << "1- saludar \n";
        cout << "2- retiro \n";
        cout << "3- salir \n \n";
        cin>>a;

        switch (a)
        {
           case 1:
           cout <<" hola te mando saludo \n";
           break;
           case 2:
           cout <<" hola me retiro \n";
           break;
           case 3:

                cout <<" Seguro que quieres ...?  SI o NO \n";
                cout <<"\n 1-SI \n";
                cout <<"\n 2-NO \n";
                cin>>b;
                if(b==1)
                {
                    return 0;
                }else{
                    return main();
                }
                break;
           default:
                return main();
                break;
           }
        }
        while (a != 3);
        system("pause");
        return main();

}


