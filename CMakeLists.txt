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
        TemplateList/Nodo.h
        TemplateList/Lista.h
)
