commands = [
    {
    "ins_index":0,
    "ins_type":"Compound_ins",
    "ins_num":2,
    "ops":[
        {"op_index":0,"op_name":"symtag1","op_input_byte":"0"*3+"1"+"0"*124,"type":"fixed"},
        {"op_index":1,"op_name":"symtag2","op_input_byte":"a"*64,"type":"input"},
    ],
    "max_use_num":10,
    "depend_index":-1
    },{
    "ins_index":1,
    "ins_type":"Compound_ins",
    "ins_num":1,
    "ops":[
        {"op_index":2,"op_name":"symtag3","op_input_byte":"0"*3+"3"+"0"*124,"type":"fixed"},
    ],
    "max_use_num":10,
    "depend_index":0
    }
    ]

normal_behavior=[[0,1]]
# print(commands)