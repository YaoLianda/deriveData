commands = [
    {
    "ins_index":0,
    "ins_type":"Compound_ins",
    "ins_num":3,
    "ops":[
        {"op_index":0,"op_name":"symtag1","op_input_byte":"0"*3+"1"+"0"*12,"type":"fixed"},
        {"op_index":1,"op_name":"symtag2","op_input_byte":"0"*3+"8"+"0"*12,"type":"input"},
        {"op_index":2,"op_name":"symtag3","op_input_byte":"1"*8,"type":"input"},
    ],
    "max_use_num":10,
    "depend_index":-1
    },    {
    "ins_index":1,
    "ins_type":"Compound_ins",
    "ins_num":2,
    "ops":[
        {"op_index":3,"op_name":"symtag4","op_input_byte":"0"*3+"3"+"0"*12,"type":"fixed"},
        {"op_index":4,"op_name":"symtag5","op_input_byte":"0"*16,"type":"input"},
    ],
    "max_use_num":10,
    "depend_index":0
    }
    ]

normal_behavior=[[0,1]]
# print(commands)