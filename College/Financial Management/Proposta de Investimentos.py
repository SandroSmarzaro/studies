import os

clear = lambda: os.system('cls' if os.name == 'nt' else 'clear')

def menu():
    clear()
    print('\n\tSELECT OPTION')
    print('\n' + '-' * 35 + '\n')
    print(' 1 - Future Value')
    print(' 2 - Present Value')
    print(' 3 - Net Present Value')
    print(' 4 - Payback')
    print(' 5 - Internal Rate of Return')
    print(' 0 - Exit')
    print('\n' + '-' * 35 + '\n')
    print(' OPTION: ', end='')
    option = int(input())

    return option

def numberPeriods():
    quantity = 0

    while quantity <= 0:
        clear()
        print('\n Insert the number of periods')
        print('\n' + '-' * 35 + '\n')
        print(' NUMBER: ', end='')
        quantity = int(input())
    
    return quantity

def rate(nameRate):
    value = -1

    while value < 0:
        clear()
        print(f'\n Insert the {nameRate}')
        print('\n' + '-' * 35 + '\n')
        print(' RATE: ', end='')
        value = float(input())
    
    return value

def insert_FV_PV(nameValue):
    value = -1

    while value < 0:
        clear()
        print(f'\n Insert the {nameValue} value\n')
        print('\n' + '-' * 35 + '\n')
        print(' VALUE: ', end='')
        value = float(input())

    return value

def basicFormula(value, rate, currentPeriod, optionFormula):
    if ( optionFormula ):
        finalValue = value * ((1 + rate) ** currentPeriod)
        return finalValue
    else:
        finalValue = value / ((1 + rate) ** currentPeriod)
        return finalValue

def calculate_FV_PV(optionValue):
    periods = numberPeriods()
    specificRate = rate('compound interest rate')

    if optionValue:
        cash = insert_FV_PV('present')
        finalvalue = basicFormula(cash, specificRate, periods, 1)
    else:
        cash = insert_FV_PV('future')
        finalvalue = basicFormula(cash, specificRate, periods, 0)
    
    return finalvalue

def printResult(result, nameResult, analyze):
    exit = 1
    while exit != 0:
        clear()
        print('\n' + '-' * 45 + '\n')
        print(f' Your {nameResult} is {result:.2f}\n')
        
        if analyze == 1:
            if result > 0:
                print(f'\tVIABLE PROPOSAL')
            elif result < 0:
                print(f'\tUNFEASIBLE PROPOSAL')
            else:
                print(f'\t\INDIFFERENT PROPOSAL')
        elif analyze == 2:
            if result == -1:
                clear()
                print('\n' + '-' * 45 + '\n')
                print(f' Your {nameResult} is NEGATIVE VALUE\n')
            global paybackPeriod
            if result == -1:
                print(f'\tUNFEASIBLE PROPOSAL')
            elif result < paybackPeriod:
                print(f'\tVIABLE PROPOSAL')
            elif result == paybackPeriod:
                print(f'\t\INDIFFERENT PROPOSAL')
            pass
        elif analyze == 3:
            MARR = rate("minimum acceptable rate of return")
            MARR *= 100
            clear()
            print('\n' + '-' * 45 + '\n')
            print(f' Your {nameResult} is {result:.2f}\n')
            if result > MARR:
                print(f'\tVIABLE PROPOSAL')
            elif result < MARR:
                print(f'\tUNFEASIBLE PROPOSAL')
            else:
                print(f'\t\INDIFFERENT PROPOSAL')
        else:
            pass

        print('\n' + '-' * 45 + '\n')
        print(' 0 for EXIT: ', end='')
        exit = int(input())

def initialInvestment():
    investment = -1
    while investment < 0:
        clear()
        print(f'\n Insert the initial investment')
        print('\n' + '-' * 35 + '\n')
        print(' INITIAL: ', end='')
        investment = float(input())

    return investment

def cashFlow(period):
    clear()
    print(f'\n Insert the {period}º cash flow')
    print('\n' + '-' * 35 + '\n')
    print(' CASH: ', end='')
    cash = float(input())

    return cash

def netPresentValue():
    finalValue = 0
    periods = numberPeriods()
    specificRate = rate('minimum acceptable rate of return')
    investment = initialInvestment()

    for count in range(0, (periods + 1)):
        if count == 0:
            finalValue -= investment
        else:
            oldCash = cashFlow(count)
            atualCash = basicFormula(oldCash, specificRate, count, 0)
            finalValue += atualCash
    
    return finalValue

def insertPayback():
    global paybackPeriod
    atualCashList = list()
    periods = numberPeriods()
    paybackPeriod = periods
    specificRate = rate('internal rate of return')
    investment = initialInvestment()

    for count in range(0, (periods + 1)):
        if count == 0:
            atualCashList.append(investment)
        else:
            oldCash = cashFlow(count)
            atualCash = basicFormula(oldCash, specificRate, count, 0)
            atualCashList.append(atualCash)
    
    return atualCashList

def payback():
    finalValue = 0
    atualCashList = insertPayback()
    for period in range(0, len(atualCashList)):
        if period == 0:
            finalValue -= atualCashList[period] 
        else:
            finalValue += atualCashList[period]
            if (finalValue < 0) and (period == (len(atualCashList) - 1)):
                return -1
            if finalValue < 0:
                minimumPeriod = period
                lastNegative = finalValue
                nextNPV = atualCashList[period + 1]
    payBack = minimumPeriod + ((-1 * lastNegative) / nextNPV)

    return payBack

def IRR():
    count = 1
    finalValue = 1
    specificRate = 0
    oldCashList = list()
    periods = numberPeriods()
    investment = initialInvestment()

    for count in range(0, (periods + 1)):
        if count == 0:
            oldCashList.append(investment)
        else:
            oldCash = cashFlow(count)
            oldCashList.append(oldCash)

    while finalValue > 0:
        if count:
            finalValue = 0
        count += 1
        specificRate += 0.0001
        for period in range(0, (periods + 1)):
            if period == 0:
                finalValue -= investment
            else:
                atualCash = basicFormula(oldCashList[period], specificRate, period, 0)
                finalValue += atualCash

    return specificRate * 100

if __name__ == '__main__':
    option = 1
    while option != 0:
        option = menu()
        if option == 0:
            pass
        elif option == 1:
            printResult(calculate_FV_PV(1), "FUTURE VALUE", 0)
        
        elif option == 2:
            printResult(calculate_FV_PV(0), "PRESENT VALUE", 0)
        
        elif option == 3:
            printResult(netPresentValue(), "NET PRESENT VALUE", 1)

        elif option == 4:
            printResult(payback(), "PAYBACK", 2)

        elif option == 5:
            printResult(IRR(), "INTERNAL RATE OF RETURN", 3)
            pass
        else:
            pass  