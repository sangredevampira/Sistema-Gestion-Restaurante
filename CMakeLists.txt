add_executable(new_target main.cpp
        "Entities cpp/Card.cpp"
        "Entities headers/Client.h"
        "Entities headers/PaymentMethod.h"
        "Entities headers/Digital.h"
        "Entities headers/Cash.h"
        "Entities cpp/Digital.cpp"
        "Entities cpp/Client.cpp"
        "Entities cpp/Cash.cpp"
        "Entities headers/Card.h"
        "Utilities/Utilities.h"
        "Entities cpp/CashRegister.cpp"
        "Entities headers/CashRegister.h"
        Exceptions/GeneralException.cpp
        Exceptions/GeneralException.h
        Exceptions/IndexOutOfRange.cpp
        Exceptions/IndexOutOfRange.h
        Exceptions/Underpayment.cpp
        Exceptions/Underpayment.h
        "Entities cpp/ClientManagement.cpp"
        "Entities headers/ClientManagement.h"
        "Entities cpp/Order.cpp"
        "Entities headers/Order.h"
        "Decorator Headers/Product.h"
        "Decorator cpp/Meal.cpp"
        "Decorator Headers/Meal.h"
        "Decorator cpp/Beverage.cpp"
        "Decorator Headers/Beverage.h"
        "Decorator cpp/Dessert.cpp"
        "Decorator Headers/Dessert.h"
        "Decorator Headers/Extras.h"
        "Decorator cpp/SmallSize.cpp"
        "Decorator Headers/SmallSize.h"
        "Decorator cpp/MediumSize.cpp"
        "Decorator Headers/MediumSize.h"
        "Decorator cpp/BigSize.cpp"
        "Decorator Headers/BigSize.h"
        "Decorator cpp/MealExtra.cpp"
        "Decorator Headers/MealExtra.h"
        "Decorator cpp/ExtraBeverage.cpp"
        "Decorator Headers/ExtraBeverage.h"
        "Decorator cpp/ExtraDessert.cpp"
        "Decorator Headers/ExtraDessert.h"
        "Decorator cpp/Extras.cpp"
        "Decorator cpp/Product.cpp"
        ListEntitie/Nodo.h
        "Decorator cpp/ProductManagement.cpp"
        "Decorator Headers/ProductManagement.h"
        "Entities cpp/Restaurant.cpp"
        "Entities headers/Restaurant.h"
        "Entities cpp/OrderManagement.cpp"
        "Entities headers/OrderManagement.h"
        "Entities cpp/Menu.cpp"
        "Entities headers/Menu.h"
        Exceptions/Miscapture.cpp
        Exceptions/Miscapture.h
        Exceptions/MissingFile.cpp
        Exceptions/MissingFile.h
        Exceptions/EmptyOrder.cpp
        Exceptions/EmptyOrder.h
        Utilities/ConsoleService.cpp
        Utilities/ConsoleService.h
)
