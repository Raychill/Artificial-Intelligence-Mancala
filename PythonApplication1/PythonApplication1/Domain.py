class Variable:
    """description of class"""
    def __init__(self, name,id):
        self.name = name
        self.domain = [0,1,2,3,4,5,6,7,8,9]
        self.id = id
        
    def print(self):
        print(self.name)
        print(self.domain)
        print(self.id)

    def __str__(self):
        return "{} {} {}".format(self.name, self.id, self.domain)