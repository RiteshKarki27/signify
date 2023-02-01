from fastkml import kml

def compute_xyz(path):
    with open(path, 'r') as myfile:
        doc = myfile.read()
    k = kml.KML()
    k.from_string(doc.encode('utf-8'))

    outerFeature = list(k.features())
    print(len(outerFeature))
    print(outerFeature[0].features())
    
    innerFeature = list(outerFeature[0].features())
    print(len(innerFeature))

    placemarks = list(innerFeature[0].features())
    print(len(placemarks))
    coords_x = []
    coords_y = []
    coords_z = []

    for p in placemarks:
        coords_x.append(p.geometry.x)  
        coords_y.append(p.geometry.y)
        coords_z.append(p.geometry.z)

    coords_x[:] = [coord - coords_x[0] for coord in coords_x]
    coords_x[:] = [coord * 10000.0 for coord in coords_x]
    coords_y[:] = [coord - coords_y[0] for coord in coords_y]
    coords_y[:] = [coord * 10000.0 for coord in coords_y]
    coords_z[:] = [coord - coords_z[0] for coord in coords_z]   

    for i in range(len(coords_x)):
        coords_x[i] = round(coords_x[i], 0)
    
    for i in range(len(coords_y)):
        coords_y[i] = round(coords_y[i], 0)

    merged = list(zip(coords_x, coords_y, coords_z))

    for i in merged:
        print(i)

    return merged