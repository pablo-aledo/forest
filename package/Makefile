all:
	tar -xzf forest_svcomp_16_2.tar.gz
	cp ../bin/forest forest/bin/forest
	cp ../lib/forest.a forest/lib/forest.a
	cp /llvm-2.9/Release+Asserts/lib/ForestHeuristic.so forest/tools/llvm-2.9/Release+Asserts/lib/ForestHeuristic.so
	cp /llvm-2.9/Release+Asserts/lib/ForestInstr.so forest/tools/llvm-2.9/Release+Asserts/lib/ForestInstr.so
	cp /llvm-2.9/Release+Asserts/lib/ForestMeasure.so forest/tools/llvm-2.9/Release+Asserts/lib/ForestMeasure.so
	cp /llvm-2.9/Release+Asserts/lib/ForestBcAnalyze.so forest/tools/llvm-2.9/Release+Asserts/lib/ForestBcAnalyze.so
	cp /llvm-2.9/Release+Asserts/lib/ForestConcurrency.so forest/tools/llvm-2.9/Release+Asserts/lib/ForestConcurrency.so
	echo 'all:' > forest/Makefile
	find -name config.xml | sed "s/\.\/forest/\t@forest ./g" >> forest/Makefile 
	rm forest_svcomp_16_2.tar.gz
	strip --strip-debug forest/bin/*
	strip --strip-debug forest/lib/*
	tar -czf forest_svcomp_16_2.tar.gz forest/*
	rm -rf forest
