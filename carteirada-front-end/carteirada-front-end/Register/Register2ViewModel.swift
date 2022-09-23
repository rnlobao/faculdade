//
//  Register2ViewModel.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 22/09/22.
//

import Foundation

class Register2ViewModel {
    
    var service: RegisterUserService?
    var delegate: ServiceDelegate?

    init(_ service: RegisterUserService? = RegisterUserService(), delegate: ServiceDelegate? = nil) {
        self.service = service
        self.delegate = delegate
    }
    
    func canWePostIt(user: Bool, email: Bool, senha: Bool) -> Bool {
            if user == true && email == true && senha == true {
                return true
            }
            return false
    }
    
    func postDataUser(login: String, email: String, password: String) {
            delegate?.showLoad()
            service?.postUser(login: login, email: email, password: password, sucess: { result in
                self.delegate?.dataSucess()
                self.delegate?.removeLoad()
            }, error: { error in
                self.delegate?.dataFail(error: error)
                self.delegate?.removeLoad()
            })
        }
}
