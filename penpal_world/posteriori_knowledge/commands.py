commands = [
   {
        "ins_index": 0,
        "ins_type": "Compound_ins",
        "ins_num": 2,
        "ops": [
            {
                "op_index": 0,
                "op_name": "symtag1",
                "op_input_byte": "0001",
                "type": "fixed",
                "func": "scanf"
            },
            {
                "op_index": 1,
                "op_name": "symtag2",
                "op_input_byte": "0000",
                "type": "input",
                "func": "scanf"
            }
        ],
        "max_use_num": 10,
        "depend_index": -1
    },
        {
        "ins_index": 1,
        "ins_type": "Compound_ins",
        "ins_num": 3,
        "ops": [
            {
                "op_index": 2,
                "op_name": "symtag3",
                "op_input_byte": "0002",
                "type": "fixed",
                "func": "scanf"
            },
            {
                "op_index": 3,
                "op_name": "symtag4",
                "op_input_byte": "0000",
                "type": "input",
                "func": "scanf"
            },
            {
                "op_index": 4,
                "op_name": "symtag5",
                "op_input_byte": "a"*72,
                "type": "input"
            }
        ],
        "max_use_num": 10,
        "depend_index": 0,
    },
       {
     "ins_index": 2,
        "ins_type": "Compound_ins",
        "ins_num": 2,
        "ops": [
            {
                "op_index": 5,
                "op_name": "symtag6",
                "op_input_byte": "0003",
                "type": "fixed",
                "func": "scanf"
            },
            {
                "op_index": 6,
                "op_name": "symtag7",
                "op_input_byte": "0000",
                "type": "input",
                "func": "scanf"
            }
        ],
        "max_use_num": 10,
        "depend_index": 0
    },
    ]

normal_behavior=[[0,1,2]]
# print(commands)