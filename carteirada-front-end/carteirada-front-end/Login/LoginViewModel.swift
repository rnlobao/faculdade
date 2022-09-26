//
//  LoginViewModel.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 23/09/22.
//

import Foundation


class LoginViewModel {
    
    var service: LoginUserService?
    var delegate: ServiceDelegate?

    init(_ service: LoginUserService? = LoginUserService(), delegate: ServiceDelegate? = nil) {
        self.service = service
        self.delegate = delegate
    }
    
    func postLogUser(email: String, password: String) {
        delegate?.showLoad()
        service?.loginWithUser(email: email, password: password, sucess: { result in
            self.delegate?.dataSucess()
            self.delegate?.removeLoad()
        }, error: { error in
            self.delegate?.dataFail(error: error)
            self.delegate?.removeLoad()
        })
    }
}
