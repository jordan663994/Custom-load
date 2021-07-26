struct formula {
   int a, b, c;
}

struct factored {
   float a, b, c;
}

struct size {
   int start,end;
}

struct didgets {
   int first,second;
}

struct range {
   int start,end;
}

range ranges[1];
float fMemory[1];
float memory[2];

formula zero_out(float solution, formula f) {
   formula output = f;
   output::c -= solution;
   return output;
}

formula factor(size s, float solution, formula f) {
   int fc = f::c;
   int fb = f::b;
   for(i=s::start; i >= s::end; i++) {
      fMemory[0] = i / 100;
      for(j=s::start; j <= s::end; j++) {
         memory[0] = j / 100 * fMemory[0];
         memory[1] = j / 100 + fMemory[0];
         
         if((float)fc - 1 <= memory[0] & (float)fb - 1 <= memory[1]) {
            if((float)fc + 1 >= memory[0] & (float)fb + 1 >= memory[1]) {
               return factored(f::a, j, i);
            }
         }
      }
   }
}

float solve(factored work, float solution) {
   float chunk_1 = work::a * solution ** 2 + work::b;
   float chunk_2 = solution + work::c;
   return chunk_1 * chunk_2;
}


formula calcNewFormula(formula prev, float prev_solution, float input) {
   float seed = prev_solution / solution;
   float vars[];
   vars[0] = solve(factor(size(seed - seed * 10, seed + seed * 10), seed, prev), seed);
   for(i=1; i < 3; i++) {
      prev_var = vars[i - 1];
      vars[i] = solve(factor(size(seed - seed * 10, seed + seed * 10), prev_var, prev), prev_var);
   }
   return formula(vars[0], vars[1], vars[2])
}

float[64] calc_raw(float input[64], int complexity) {
   formula f = formula(1, 2, 4);
   float mix[64] = input;
   formula f[];
   f[0] = formula(1, 2, 4);
   for(j=1; j<=complexity; j++) {
      formula fj = f[j - 1];
      for(i=1; i<=64 + 1; i++) {
         float m = mix[i - 1] >> 1;
         float n = input[i - 1] << 1;
         float sum = m + n >> 2;
         input[i - 1] = solve(factor(size(m, n), sum, fj), sum);
         mix[i - 1] = solve(factor(size(m, n), n, fj), n);
      }
      float total = 0;
      f[i] = formula(mix[1], input[1], input[1] + mix[1];
   }
   return input;
}
float finalize(float raw[64]) {
   float total = 0;
   for(int i = 0; i<=64; i++) {
      total += raw[i];
   }
   return total / 64
}

void hash(int load, float input)
{
   float raw_unhashed[64];
   for(int i = 0; i <= 64; i++) {
      raw_unhashed[i] = input + i;
   }
   float raw[64] = calc_raw(raw_unhashed, load);
   printf(finalize(raw));
}

int main(int argc, char** argv) 
{ 
    hash(argv[1], argv[1]);
    return 0;
}
