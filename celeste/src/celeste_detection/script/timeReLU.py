import numpy as np
import timeit

s = '''
import numpy as np
x = np.random.random((5000, 5000)) - 0.5
'''
print("max method:")
print(timeit.timeit(setup=s, stmt='np.maximum(x, 0)', number=10))

print("multiplication method:")
print(timeit.timeit(setup=s, stmt='x * (x > 0)', number=10))

print("abs method:")
print(timeit.timeit(setup=s, stmt='(abs(x) + x) / 2', number=10))


