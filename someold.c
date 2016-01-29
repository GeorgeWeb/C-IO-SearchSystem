// check if file exists
    if (Exists(ifh) && Exists(ofh))
    {
		// read from file -> write to file

		printf("\nSTAGE 1\n");
		
		// allocate specific memory
		char *line = malloc(m_File->line_size);
		char *str = malloc(64);
		
		// Search in file (from stdin) and Write in output file
		Search_File(ifh, ofh, m_File, line, str);
		
		// !!! REFERENCE 2: open file -> search for matching string -> (outputting it if matches) -> writing it to output file
		
		// Write line to output File
		//Write_File(ofh, m_File, line);
		
		free(str);
		free(line);
		
		Close(ofh);
		Close(ifh);
		
		
    }
    else if(Exists(ifh) && !Exists(ofh))
	{
		// read from file -> write to std
	
		printf("\nSTAGE 2\n");
	
		// allocate specific memory
		char *line = malloc(m_File->line_size);
		
		// Search in file (from stdin) and Write to stdout
		Search_File(ifh, ofh, m_File, line, str);
		//Write_Std_FromFile(ifh, m_File, line);
	
		free(line);
	
		Close(ifh);
	}
	else if (!Exists(ifh) && Exists(ofh))
	{
		// read from std -> write to file
		
		printf("\nSTAGE 3\n");
		
		char *line = malloc(sz);
		
		// Read line from stdin
		Read_Std(line, sz);
		
		// Write line to output File
		Write_File(ofh, m_File, line);
		
		Close(ofh);
		
		free(line);
	}
	else // both do not exist
	{
		// read from std -> write to std
		
		printf("\nSTAGE 4\n");
		
		char *line = malloc(sz);
		
		// Read line from stdin
		Read_Std(line, sz);
		
		// Write line to stdout
		Write_Std(line);

		free(line);
	}