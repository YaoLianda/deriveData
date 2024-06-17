commands = [
    {
    "ins_index":0,
    "ins_type":"Compound_ins",
    "ins_num":2,
    "ops":[
        {"op_index":0,"op_name":"symtag1","op_input_byte":"0001"+"0"*27,"type":"fixed"},
        {"op_index":1,"op_name":"symtag2","op_input_byte":"a"*64,"type":"input"}
    ],
    "max_use_num":3,
    "depend_index":-1
    },
     {
    "ins_index":1,
    "ins_type":"Compound_ins",
    "ins_num":3,
    "ops":[
        {"op_index":2,"op_name":"symtag3","op_input_byte":"0002"+"0"*27,"type":"fixed"},
        {"op_index":3,"op_name":"symtag4","op_input_byte":"0000"+"0"*27,"type":"input"},
        {"op_index":4,"op_name":"symtag5","op_input_byte":"b"*64,"type":"input"}
    ],
    "max_use_num":3,
    "depend_index":0
    },
        {
    "ins_index":2,
    "ins_type":"Compound_ins",
    "ins_num":3,
    "ops":[
        {"op_index":5,"op_name":"symtag6","op_input_byte":"0003"+"0"*27,"type":"fixed"},
        {"op_index":6,"op_name":"symtag7","op_input_byte":"0000"+"0"*27,"type":"input"},
        {"op_index":7,"op_name":"symtag8","op_input_byte":"NN","type":"input"}
    ],
    "max_use_num":3,
    "depend_index":0
    }
     
    ]

normal_behavior=[[0,1,2]]
# print(commands)