commands = [
    {
    "ins_index":0,
    "ins_type":"single_ins",
    "ins_num":1,
    "ops":[
        {"op_index":0,"op_name":"symtag1","op_input_byte":"a"*16,"type":"input"},
    ],
    "max_use_num":1,
    "depend_index":-1
    },
     {
    "ins_index":1,
    "ins_type":"Compound_ins",
    "ins_num":3,
    "ops":[
        {"op_index":1,"op_name":"symtag2","op_input_byte":"0001"+"0"*12,"type":"fixed"},
        {"op_index":2,"op_name":"symtag3","op_input_byte":"b"*16,"type":"input"},
        {"op_index":3,"op_name":"symtag4","op_input_byte":"0089"+"0"*12,"type":"input"},
    ],
    "max_use_num":40,
    "depend_index":-1
    },
    {
    "ins_index":2,
    "ins_type":"Compound_ins",
    "ins_num":2,
    "ops":[
        {"op_index":4,"op_name":"symtag5","op_input_byte":"0005"+"0"*12,"type":"fixed"},
        {"op_index":5,"op_name":"symtag6","op_input_byte":"0"*16,"type":"input"},
    ],
    "max_use_num":40,
    "depend_index":0
    }
    ]

normal_behavior=[[0,1,2]]
must_run = [0]
# print(commands)