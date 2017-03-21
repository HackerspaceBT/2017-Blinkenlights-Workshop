import cv2, gc
from numpy import *
gc.collect()

N = 256  # Cube side length

# Create 3-dimensional rgb-cube
# (stupid method, since we only need the 6 surfaces)
cube = zeros((N,N,N,3), dtype=uint8)
cube[:,:,:,0] = arange(N)[:, newaxis, newaxis]  # blue
cube[:,:,:,1] = arange(N)[newaxis, :, newaxis]  # green
cube[:,:,:,2] = arange(N)[newaxis, newaxis, :]  # red

rg = cube[0,:,:]  # red - green
rb = cube[:,0,:]  # red - blue
gb = cube[:,:,0]  # green - blue
cm = cube[-1,:,:]  # cyan - magenta
cy = cube[:,-1,:]  # cyan - yellow
my = cube[:,:,-1]  # magenta - yellow

# Construct surface net
net = full((4*N, 3*N, 3), 255, dtype=uint8)
net[N:2*N, 0:N, :] = fliplr( gb )
net[0:N, N:2*N, :] = flipud( rg )
net[N:2*N, N:2*N, :] = rb
net[2*N:3*N, N:2*N, :] = cm
net[3*N:4*N, N:2*N, :] = flipud(cy)
net[N:2*N, 2*N:3*N, :] = my


cv2.imwrite('rgbnet.png', net)
##cv2.imwrite('rg.png', rg)
##cv2.imwrite('rb.png', rb)
##cv2.imwrite('gb.png', gb)
##cv2.imwrite('cm.png', cm)
##cv2.imwrite('cy.png', cy)
##cv2.imwrite('my.png', my)
