import sys

class Matrix:
    """Creates a Matrix object"""
    def __init__(self, array=None):
        """Takes matrix as the argument"""
        
        if array==None:
            array = []
        self.m = array
        self.r = len(array)
        try:
            self.c = len(array[0])
        except:
            self.c = 0
            return None
        
    def create(self, r, c):
        """Create new matrix"""
        self.r = r
        self.c = c
        for i in range(self.r):
            row = []
            for j in range(self.c):
                try:
                    e = eval(input('Enter element at '+str(i+1)+','+str(j+1)+': '))
                except:
                    sys.stderr.write('Invalid input!!\n')
                    e = eval(input('Enter element at '+str(i+1)+','+str(j+1)+': '))
                row+=[e]
            self.m+=[row]
    
    def dimension(self):
        """Returns the dimensions of the matrix"""
        print(self.r,'x',self.c)
    
    def __add__(self, other):
        """Adds two matrices"""
        if self.r==other.r and self.c==other.c:
            l = []
            for i in range(self.r):
                row = []
                for j in range(self.c):
                    row+=[self.m[i][j]+other.m[i][j]]
                l+=[row]
            return l
        else:
            sys.stderr.write('Addition operation not defined\n')
        
    def __sub__(self, other):
        """Subtracts two matrices"""
        if self.r==other.r and self.c==other.c:
            l = []
            for i in range(self.r):
                row = []
                for j in range(self.c):
                    row+=[self.m[i][j]-other.m[i][j]]
                l+=[row]
            return l
        else:
            sys.stderr.write('Subtraction operation not defined\n')
            
    def __mul__(self, other):
        """Multiplies two matrices
        For scalar multiplication give the second operand as an float and 
        the first operand as Matrix"""
        if type(other)==int:
            for i in range(len(self.m)):
                for j in range(len(self.m[0])):
                    self.m[i][j] = other*self.m[i][j]
            return self.m
        else:
            if self.c==other.r:
                l = []
                for i in range(self.r):
                    row = []
                    for j in range(other.c):
                        ele = 0
                        for k in range(self.c):
                            ele+=self.m[i][k]*other.m[k][j]
                        row+=[ele]
                    l+=[row]
                return l
            else:
                sys.stderr.write('Vector matrix multiplication operation not defined\n')
    
    def det(self):
        """Returns the determinant of the matrix"""
        if self.r==self.c:
            l = self.m
            
            def split(l, i, j):
                l1 = []
                for r in range(len(l)):
                    l2 = []
                    for c in range(len(l[0])):
                        if r!=i and c!=j:
                            l2.insert(c, l[r][c])
                    l1+=[l2]
                l1.remove([])
                return l1
            
            def cal(l):
               if len(l)==1:
                   return l[0][0]
               elif len(l)==2:
                   return l[0][0]*l[1][1]-l[0][1]*l[1][0]
               else:
                   d = 0
                   i = 0
                   l1 = []
                   for j in range(len(l[0])):
                       d+=(-1)**(i+j+2)*l[i][j]*cal(split(l,i, j))
                       l1+=[d]
                   return d
            return cal(l)
        else:
            sys.stderr.write('Determinant does not exist\n')
    
    def transpose(self):
        """Returns the transpose of the matrix"""
        l1 = []
        for i in range(self.c):
            l2 = []
            for j in range(self.r):
                l2.append(self.m[j][i])
            l1+=[l2]
        return l1
    
    def element(self, r, c):
        """Returns the element at row r and column c of the matrix"""
        return self.m[r-1][c-1]
        
    def adj(self):
        """Returns the adjoint matrix"""
        l = self.m
        if len(l)==1:
            return l
        else:
            def split(l, i, j):
                l1 = []
                for r in range(len(l)):
                    l2 = []
                    for c in range(len(l[0])):
                        if r!=i and c!=j:
                            l2.insert(c, l[r][c])
                    l1+=[l2]
                l1.remove([])
                return l1
            
            def cal(l):
                l1 = []
                for i in range(len(l)):
                    l2 = []
                    for j in range(len(l[i])):
                        l2+=[(-1)**(i+j+2)*Matrix(split(l, i, j)).det()]
                    l1+=[l2]
                return l1
            
            m = Matrix(cal(l))
            return m.transpose()
       
    def inverse(self):
        """Returns the inverse of the matrix if it exists"""
        if self.det()==0:
            sys.stderr.write('Matrix is not invertible\n')
        elif len(self.m)==1:
            return self.m
        else:
            d = self.det()
            tmp = self.adj()
            
            for i in range(len(tmp)):
                for j in range(len(tmp[i])):
                    tmp[i][j] = tmp[i][j]/d
            return tmp
            
    def view(self):
        """Displays the matrix"""
        for i in self.m:
            print('\t')
            for j in i:
                print(j, end='   ')
            print()


#1 Dimensional Matrix          
M1 = Matrix([[5]])
#2 Dimensional Matrix
M2 = Matrix([[1,2],[3,4]])
#3 Dimensional Matrix
M3 = Matrix([[1,2,3],[4,5,6],[7,8,9]])
