import angr
p = angr.Project("./baby_tcache")
print(p.loader.main_object.plt)
print("1")