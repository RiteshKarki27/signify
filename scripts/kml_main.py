from kml_parse import *

path = r'C:\Users\I-Ritesh.K\Documents\QGroundControl\Missions\plan1_sample.kml'

merge = compute_xyz(path)
merge1 = tuple(merge)
print(type(merge1))
print(merge1)
