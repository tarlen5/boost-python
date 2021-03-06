"""
>>> from konstantin_aslanidi_ext import *
>>> go('string')
'string'
>>> go((1,2,3,4,5))
'(1, 2, 3, 4, 5)'
>>> go(((1,2),(3,4)))
'((1, 2), (3, 4))'
>>> go(((1,2,(3,4)),(5,6, (7,8))))
'((1, 2, (3, 4)), (5, 6, (7, 8)))'
"""
