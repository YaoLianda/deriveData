#from s2eproject import S2EProject
#import S2EProject
from maze import S2EProject
from maze import Maze
from maze import ExplorePath
#from maze import VulnerabilityFinder
from IPython import *
import json
from ipdb import *
#from maze import Strategy
from maze import HeapOp
import os
#from maze import TreeProcessing

#from maze import Strategy

mz=Maze(binary_path='./quotes_list',
	      s2e_project_path='/home/s2e/s2e/projects/quotes_list',
              s2e_base_path='/home/s2e/s2e/',
		ida_base_path='/home/s2e/ida-7.0/')
#os.system('rm /home/s2e/s2e/projects/quotes_list/quotes_list')
#os.system('ln -s /home/s2e/test_mzrovise/quotes_list/quotes_list /home/s2e/s2e/projects/quotes_list/quotes_list')
libc=[0x7ffff7a3a000,0x39b000]
stack=[0x7ffffffde000,0x21000]
heap=[0x603000,0x21000]
bss=[0x6020A0,0x1000-0xa0]

mz.setParameters(bss,heap,stack,libc)
mz.setMazeCfg()
mz.getAllPaths()

#mz.runPoc('./PoC')
#json.dump(mz.poc_path['trace_names'],open('./pocPaths','wb'))
#exit(0)
    
pocPaths=json.load(open('./pocPaths','rb'))
heapops=json.load(open(os.path.join(mz.sp.s2e_project_path,'poc_dir','HeapOperations')))

ho=HeapOp()
ho.get_abstract_heapop(heapops,'./poc_heapops')
mz.preparePlugins(False,False,False,False,False)
mz.sp.use_HeapSelector('./poc_heapops')
mz.sp.use_ForkLimiter(200,5)
ExplorePath(pocPaths,'',bss,heap,stack,'GenExp').run(mz)
exit(0)



#mz.runPoc('./poc')
mz.AnalysisPathDependences()
mz.saveAllAnalysedPaths(False,True)

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
