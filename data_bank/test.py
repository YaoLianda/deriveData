#from s2eproject import S2EProject
#import S2EProject
from maze import S2EProject
from maze import Maze
from maze import ExplorePath
#from maze import VulnerabilityFinder
from IPython import *
import json
from ipdb import *
import os
#from maze import Strategy
from maze import HeapOp
#from maze import TreeProcessing

#from maze import Strategy

mz=Maze(binary_path='./data_bank',
	      s2e_project_path='/home/s2e/s2e/projects/data_bank',
              s2e_base_path='/home/s2e/s2e/',
		ida_base_path='/home/s2e/ida-7.0/')
#os.system('rm /home/s2e/s2e/projects/data_bank/asvdb')
#os.system('ln -s /home/s2e/test_mzrovise/data_bank/asvdb /home/s2e/s2e/projects/asvdb/asvdb')
libc=[0x7ffff7a3a000,0x39b000]
stack=[0x7ffffffde000,0x21000]
heap=[0x555555757000,0x21000]
bss=[0x555555756000,0x1000]

mz.setParameters(bss,heap,stack,libc)
mz.setMazeCfg()
mz.getAllPaths(bad_addrs=[0x555555554B48,0x555555554D79])
#mz.AnalysisPathDependences(10,40,1,False,2)
#exit(0)

#mz.runPoc('./PoC')
#json.dump(mz.poc_path['trace_names'],open('./pocPaths','wb'))
#exit(0)
    
pocPaths=json.load(open('./pocPaths','rb'))
heapops=json.load(open(os.path.join(mz.sp.s2e_project_path,'poc_dir','HeapOperations')))
ho=HeapOp()
ho.get_abstract_heapop(heapops,'./poc_heapops')
mz.preparePlugins(False,False,False,False,False)
mz.sp.use_HeapSelector('./poc_heapops')
mz.sp.use_ForkLimiter(-1,5)
ExplorePath(pocPaths,'',bss,heap,stack,'GenExp').run(mz)
exit(0)




'''
mz.preparePlugins()
mz.sp.use_ForkLimiter(40,5)
p1=ExplorePath(['./traces/trace0','./traces/trace6'],'',bss,heap,stack).run(mz)
#p2=ExplorePath(['./traces/trace4'],'',bss,heap,stack).run(mz)
embed()
exit(0)
'''
mz.AnalysisPathDependences(10,40,1,False,2)
mz.loadAllAnalysedPaths(True, True)
embed()
exit(0)

HeapOp.fix_realloc(mz.poc_path['HeapOperations'])
vf = VulnerabilityFinder(oplist = mz.poc_path['HeapOperations'])
vf.begin()
#set_trace()
st = Strategy(vf.vul , mz.poc_path , mz.single_paths , mz.combined_paths)
st.gen_stategy_tree()
tp = TreeProcessing(st.tree, mz.single_paths , mz.combined_paths)
tp.Process_tree()

embed()
