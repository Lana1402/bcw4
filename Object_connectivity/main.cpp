#include "Category.hpp"
#include "Item.hpp"
#include "Order.hpp"
#include "Customer.hpp"

int main() {
    Category* phone = new Category("Phone");
    Category* watch = new Category("Watch");

    // delete watch;

    Item* i = new Item("iPhone", phone);
    Item* s = new Item("Samsung", phone);
    Item* iW = new Item("Apple Watch", watch);
    Item* sW = new Item("Galaxy Watch", watch);

    Customer* lana = new Customer("Lana");
    Customer* roma = new Customer("Roma");

    Order* lanaPhoneI = new Order(lana, i);
    Order* lanaPhoneS = new Order(lana, s);
    Order* lanaWatch = new Order(lana, iW);

    Order* romaPhone = new Order(roma, i);
    Order* romaWatch = new Order(roma, iW);


    // delete phone;
    // delete iW;
    delete lanaPhoneI;

    // phone->getItemsInCategory();
    // lanaPhoneS->getItemsInOrder();

    // romaPhone->addItem(s);

    // romaPhone->getItemsInOrder();

    // lana->addOrder(lanaPhone);
    // lana->addOrder(lanaWatch);


    // s->getOrder();
    // iW->getOrder();

    lana->getOrder();

    // Category::getAllCategorys();
    // Item::getAllItems();
    // Order::getAllOrders();
    // Customer::getAllCustomers();

    return 0;

}
