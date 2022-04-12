"""
PARANOIA
- IMPORT A LOG FILE
- THE FILE HAS 3 COLUMNS:
    - THE MONTH
    - THE PURPOSE
    - THE AMOUNT
- SEARCH FOR INCONSISTENCIES BETWEEEN THE MONTHS
- THE MONTH IS EXPRESED WITH THE FIRST 3 CHARACTERS
- THE PURPOSE CAN BE:
    - SLR -> SALARY
    - ENT -> ENTERTAINMENT
    - OTR -> OTHER
- THE AMOUNTS CAN BE:
    - K -> THOUSAND
    - M -> MILLION
    - B -> BILLION
"""

class inconsistencies:
    def __init__(self):
        self.months = []
        self.purposes = []
        self.amounts = []

    def process_information(self, month, purpose, amount, sufix):
        if month != "jan" and month != "feb" and month != "mar" and month != "apr" and month != "may" and month != "jun" and month != "jul" and month != "aug" and month != "sep" and month != "oct" and month != "nov" and month != "dec":
            print("The specified month is incorrect")
            return

        elif purpose != "slr" and purpose != "ent" and purpose != "otr":
            print("The specified purpose is incorrect, must be \"SLR\", \"ENT\" or \"OTR\"")
            return

        elif sufix != "k" and sufix != "m" and sufix != "b":
            print("The specified sufix is incorrect, must be \"K\", \"M\" or \"B\"")
            return

        else:
            if sufix == "k":
                amount *= 1000
            elif sufix == "m":
                amount *= 1000000
            elif sufix == "b":
                amount *= 1000000000

        cont = 0
        index = 0
        for i in self.months:
            if i == month:
                index = cont
            cont += 1
        if index == 0:
            index = cont
        index += 1
        self.months.insert(index, month)
        self.purposes.insert(index, purpose)
        self.amounts.insert(index, amount)
        return

    def show_inconsistencies(self):
        month_iterator = []
        cont = 0
        index = 0
        for i in self.months:
            if cont+1 < len(self.months):
                if i != self.months[cont+1]:
                    month_iterator.append(index+1)
                    cont += 1
                    index = 0
                else:
                    cont += 1
                    index += 1
            else:
                month_iterator.append(index+1)
                break
        for i in month_iterator:
            if i != month_iterator[1]:
                print("There is an inconsistency on the amount of transactions made between months")
                return
            else:
                continue

        for i in range(month_iterator[0]):
            for a in range(len(month_iterator)-1):
                if self.purposes[i] == self.purposes[month_iterator[0]*(a+1)+i]:
                    continue
                else:
                    print("There is an inconsistency on the type of the transactions between months")
                    return

        for i in range(month_iterator[0]):
            for a in range(len(month_iterator)-1):
                if self.amounts[i] == self.amounts[month_iterator[0]*(a+1)+i]:
                    continue
                else:
                    print("There is an inconsistency on the amount of money between months")
                    return

        print("Everything Correct")



byte_corp = inconsistencies()
while True:
    try:
        entry = input("Insert a log: ")
        if entry == "quit":
            byte_corp.show_inconsistencies()
            break

        else:
            month, purpose, amount, sufix = entry.split(" ")
            month = month.lower()
            purpose = purpose.lower()
            amount = int(amount)
            sufix = sufix.lower()
            byte_corp.process_information(month, purpose, amount, sufix)

    except:
        print("The structure must be: [month] [purpose] [amount] [sufix]")
        continue