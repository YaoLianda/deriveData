commands = [
    {
    "ins_index":0,
    "ins_type":"Compound_ins",
    "ins_num":2,
    "ops":[
        {"op_index":0,"op_name":"symtag1","op_input_byte":"0"*3+"1"+"0"*4,"type":"fixed"},
        {"op_index":1,"op_name":"symtag2","op_input_byte":"00000000","type":"input"},
        {"op_index":2,"op_name":"symtag3","op_input_byte":"a"*1024,"type":"input"},
    ],
    "max_use_num":3,
    "depend_index":-1
    }
    ]

normal_behavior=[[0]]
# print(commands)