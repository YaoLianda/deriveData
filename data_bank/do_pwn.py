#from s2eproject import S2EProject
#import S2EProject
from maze import S2EProject
from maze import Maze
from maze import ExplorePath
from maze import VulnerabilityFinder
from IPython import *
import json
from ipdb import *
#from maze import Strategy
#from maze import HeapOp
#from maze import TreeProcessing
from maze.benchmark import *
from maze.heapop import *
from maze.LayoutAnalysis.ConcolicExecutor import *
from maze.config import *

mz=Maze(binary_path='./data_bank',
	      s2e_project_path='/home/s2e/s2e/projects/data_bank',
              s2e_base_path='/home/s2e/s2e/',
       ida_base_path='/home/s2e/ida-7.0/')

#libc=[0x7ffff7834000,0x39b000]
libc=[0x7ffff7a3a000,0x39b000]
stack=[0x7ffffffde000,0x21000]
heap=[0x0000555555757000,0x21000]
bss=[0x555555756010+0x10,0x1000-0x10]

#s2e_cfg_file='./static_analysis/rnote2.cfg'
#bbinfo_file='./static_analysis/rnote2.bbinfo'
#static_analysis_file='./static_analysis/rnote2.static_analysis'

mz.setParameters(bss,heap,stack,libc)

#mz.setMazeCfg()
#mz.getAllPaths(bad_addrs=[])

#mz.runPoc('./poc')
#mz.AnalysisPathDependences()
#mz.saveAllAnalysedPaths()
#mz.saveAllAnalysedPaths(True , False)
#exit(0)

mz.loadAllAnalysedPaths(True,True)
t1 = time.time()
#remove start
remove_list = []
for pi in range(0, len(mz.single_paths)):
    p = mz.single_paths[pi]
    if p['trace_name'][0].find("start")>=0:
        remove_list.append(pi)
for pi in remove_list:
    mz.single_paths.remove(mz.single_paths[pi])

remove_list = []
for pi in range(0, len(mz.combined_paths)):
    p = mz.combined_paths[pi]
    if p['trace_name'][0].find("start")>=0:
        remove_list.append(pi)
for pi in remove_list:
    mz.combined_paths.remove(mz.combined_paths[pi])



#set_trace()
#mz.poc_path = {}
#mz.poc_path['trace_names'] = []
#poc_trace_name = json.load(open('./pocPaths','rb'))
#fp = open('./poc_heapops','rb')
#poc_heapop = []
#vul_id_list = [5]
#max_enum_size = 0x50
#for h in fp:
#    h = h.strip()
#    h = h.split(" ")
#    for hi in range(len(h)):
#        if h[hi].isdigit():
#            h[hi] = int(h[hi])
#    if get_trace_info(poc_trace_name, h[2])[0].find('start')>=0:
#        continue
#    if h[0] == 0 or h[0] == 1 or h[0] == 3 or h[0] == 5:
#        poc_heapop.append(h)
#    elif h[0] == 4:
#        if h[3] in vul_id_list:
#            poc_heapop.append(h)
#    elif h[0] == 6:
#        if h[4] in vul_id_list:
#            poc_heapop.append(h)
#fp.close()
#set_trace()
#vulid_dict.append(3)
max_enum_size.append(0x90)
poc_trace_name = mz.poc_path["trace_names"]
(tmp_poc_heapop, _ )= get_abstract_heapop(mz.poc_path["HeapOperations"], 'tmp')
poc_heapop = []
for h in tmp_poc_heapop:
    if get_trace_info(poc_trace_name, h[2])[0].find('start')>=0:
        continue
    poc_heapop.append(h)

ex_init = ConcolicExecutor([], malloctype = PTMALLOC)
ex_init.core.start()

layoutman = LayoutMan(mz.single_paths, mz.combined_paths)
layoutman.get_heap_op()
layoutman.ex_init = ex_init


mdata = measure_data(0, 2, 237)
flag, heapop, trace_name, ret_mdata = dig_and_fill_equation(layoutman, poc_heapop, poc_trace_name, mdata)
ex_init.stop_core()

f = open('./exp_trace_name','wb')
json.dump(trace_name, f )
f.close()

f = open('./exp_heapop','wb')
json.dump(heapop, f )
f.close()

t2 = time.time()
print t2-t1
set_trace()


'''
HeapOp.fix_realloc(mz.poc_path['HeapOperations'])
vf = VulnerabilityFinder(oplist = mz.poc_path['HeapOperations'])
vf.begin()
st = Strategy(vf.vul , mz.poc_path , mz.single_paths , mz.combined_paths)
st.gen_stategy_tree()
tp = TreeProcessing(st.tree, mz.single_paths , mz.combined_paths)
tp.Process_tree()
#set_trace()
for e in tp.exp_list:
    set_trace()
    HeapOp.save_heapop('exp', e[1])
    mz.preparePlugins(False,False,False,False,False)
    mz.sp.use_HeapSelector('./exp')
    mz.sp.use_ForkLimiter(-1,5)
    ExplorePath(e[0],'',bss,heap,stack).run(mz)
    #mz.runTracer(e[0],0,False)
embed()
'''
