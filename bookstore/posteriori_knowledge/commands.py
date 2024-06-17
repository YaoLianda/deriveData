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
    }
    ]

normal_behavior=[[0]]
# print(commands)