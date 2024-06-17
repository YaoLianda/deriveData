commands = [
    {
    "ins_index":0,
    "ins_type":"Compound_ins",
    "ins_num":4,
    "ops":[
        {"op_index":0,"op_name":"symtag1","op_input_byte":"0001"+"0"*4,"type":"fixed"},
        {"op_index":1,"op_name":"symtag2","op_input_byte":"0008"+"0"*4,"type":"input"},
        {"op_index":2,"op_name":"symtag3","op_input_byte":"a"*8,"type":"input"},
        {"op_index":3,"op_name":"symtag4","op_input_byte":"a"*24,"type":"input"}
    ],
    "max_use_num":100,
    "depend_index":-1
    },{
    "ins_index":1,
    "ins_type":"Compound_ins",
    "ins_num":2,
    "ops":[
        {"op_index":4,"op_name":"symtag5","op_input_byte":"0003"+"0"*4,"type":"fixed"},
        {"op_index":5,"op_name":"symtag6","op_input_byte":"0"*8,"type":"input"}
    ],
    "max_use_num":100,
    "depend_index":0
    }
    ]

normal_behavior=[[0,1]]
# print(commands)