Shopping Cart System 

This is a basic C++ console application that simulates a shopping cart interface. It uses a "ShoppingCart" class that contains a vector of "Item" objects that have various attributes. There is also a Utility class to handle printing the interface and calling different methods based on user input. The program runs continuously until you decide to quit by entering 'q'. 

Techniques Used
>Vectors
>Output String Stream (similar to java string builder)
>Switch Statement
>While loop 
>string::npos (used in search operation)


Example Program Output

Enter customer's name: Sam
Enter today's date:7/22/2020

Customer name: Sam
Today's date: 7/22/2020
MENU
a - Add item to cart <------------(Selection)
d - Remove item from cart
c - Change item quantity
i - Output items' descriptions
o - Output shopping cart
q - Quit
Choose an option:
a

ADD ITEM TO CART<--------------------(Output)
Enter the item name:
bannana
Enter the item description:
yellow fruit
Enter the item price:
2
Enter the item quantity:
10

MENU
a - Add item to cart <------------(Selection)
d - Remove item from cart
c - Change item quantity
i - Output items' descriptions
o - Output shopping cart
q - Quit
Choose an option:
a

ADD ITEM TO CART<-------------------(Output)
Enter the item name:
cucumber
Enter the item description:
green vegetable
Enter the item price:
3
Enter the item quantity:
10

MENU
a - Add item to cart
d - Remove item from cart
c - Change item quantity
i - Output items' descriptions
o - Output shopping cart <-------(Selection)
q - Quit
Choose an option:
o

OUTPUT SHOPPING CART<--------------(Output)
Sam's Shopping Cart - 7/22/2020
Number of Items: 20

bannana 10 @ $2.00 = $20.00
cucumber 10 @ $3.00 = $30.00
Total: $50.00

MENU
a - Add item to cart
d - Remove item from cart<-------(Selected)
c - Change item quantity
i - Output items' descriptions
o - Output shopping cart
q - Quit
Choose an option:
d

REMOVE ITEM FROM CART<------------(Output)
Enter name of item to remove:
banana

MENU
a - Add item to cart
d - Remove item from cart
c - Change item quantity<-------(Selected)
i - Output items' descriptions
o - Output shopping cart
q - Quit
Choose an option:
c

CHANGE ITEM QUANTITY<------------(Output)
Enter the item name:
cucumber
Enter the new quantity:
5

MENU
a - Add item to cart
d - Remove item from cart
c - Change item quantity
i - Output items' descriptions
o - Output shopping cart<------(Selected)
q - Quit
Choose an option:
o

OUTPUT SHOPPING CART<------------(Output)
Sam's Shopping Cart - 7/22/2020
Number of Items: 5

cucumber 5 @ $3.00 = $15.00
Total: $15.00

MENU
a - Add item to cart
d - Remove item from cart
c - Change item quantity
i - Output items' descriptions
o - Output shopping cart
q - Quit
Choose an option: