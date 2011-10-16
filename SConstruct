import os
env = Environment(ENV = {'PATH': os.environ['PATH'], 'HOME': os.environ['HOME']})
env.Append(CXXFLAGS = ['-Wall'])
env.Append(CXXFLAGS = ['-ISDLEngine'])
env.AppendUnique(LIBS = ['SDL', 'SDLmain', 'SDL_image', 'GL'])
env.Program(target = "sdlEngine", source = [Glob('SDLEngine/*.cpp'), Glob('test/*.cpp')])
