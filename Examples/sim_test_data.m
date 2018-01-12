clear;

% Step size
T=1;

% Input values
TestInput.time = (0:100)'*T;
TestInput.signals.values = uint16(mod([0:100],10)');
TestInput.signals.dimensions = 1;
